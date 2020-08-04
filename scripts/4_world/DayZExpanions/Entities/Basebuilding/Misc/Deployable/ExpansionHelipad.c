modded class ExpansionHelipad: ExpansionBaseBuilding 
{
	protected bool m_AwaitingSnap;
	
	void ExpansionHelipad(){
		m_AwaitingSnap = false;
		RegisterNetSyncVariableBool("m_AwaitingSnap");
	}
	
	bool  IsAwaitingSnap(){
		return m_AwaitingSnap;
	}
	
	override void EEInit()
	{
		super.EEInit();
		if (GetGame().IsServer()){
			if (GetSnapHeliSettings().EnableOnHeliPad)
			{
				Print( "[SnapHeliToHeliPad] " + GetType() + " init at " + GetPosition());
				m_AwaitingSnap = true;
				SetSynchDirty();
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.FindClosestHeli, 4800, false );
			}
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSnapHeliToHeliPad);
	}
	
	void ActionFindClosestHeli(){
		if (GetGame().IsServer() && GetSnapHeliSettings().EnableSnapHeliAction){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.FindClosestHeli, 3000, false );
			m_AwaitingSnap = true;
			SetSynchDirty();
		}
	}
	
	void FindClosestHeli(){
		if(GetGame().IsServer()){
			float closestDisRef = GetSnapHeliSettings().Radius + 1;
			float closestDisDefault = closestDisRef;
			ref ExpansionHelicopterScript closestHeliRef;
			int closestIndexRef = -1;
			ref array<Object> objects = new array<Object>;
			ref array<CargoBase> proxy = new array<CargoBase>;
			GetGame().GetObjectsAtPosition3D(this.GetPosition(), GetSnapHeliSettings().Radius, objects, proxy);
			for ( int i = 0; i < objects.Count(); i++ ) 
			{
				Object obj = objects.Get(i);
				if (obj.IsInherited(ExpansionHelicopterScript))
				{
					ExpansionHelicopterScript heli = ExpansionHelicopterScript.Cast(obj);
					float curdist = vector.Distance(GetPosition(), heli.GetPosition());
					if (curdist <= closestDisRef){
						closestDisRef = curdist;
						closestIndexRef = i;
						closestHeliRef = ExpansionHelicopterScript.Cast(obj);
					}
				}
			}
			
			if (closestDisRef != closestDisDefault && closestHeliRef && closestIndexRef != -1)
			{						
						
				Print( "[SnapHeliToHeliPad] " + GetType() + " at " + GetPosition() + " Found " + closestHeliRef.GetType() +  " at " + closestHeliRef.GetPosition());
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.SnapHeliToHeliPad, 1200, false, closestHeliRef ); //Find calling twice make it more stable
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.SnapHeliToHeliPad, 1250, false, closestHeliRef );
			} else {
				m_AwaitingSnap = false;
				SetSynchDirty();
			}
		}
	}
	
	void SnapHeliToHeliPad( ref ExpansionHelicopterScript heli){
		ref ExpansionHelicopterScript Heli = ExpansionHelicopterScript.Cast(heli);
		if(Heli){ //Just a double check to be safe :)
			if (!Heli.EngineIsOn() && !Heli.IsLocked()){
				SetVelocity(Heli, vector.Zero);
				
				dBodyActive( Heli, ActiveState.INACTIVE );
				dBodyDynamic( Heli, false );
				vector heliPadOrientation = GetOrientation();
				vector heliPadPosition = GetPosition();
				
				vector heliOrientation = Heli.GetOrientation();
				float heightAdjust = heliPadPosition[1] + GetSnapHeliSettings().OtherHeightAdjustment;
				if (ExpansionMh6.Cast(Heli)){
					heightAdjust = heliPadPosition[1] + GetSnapHeliSettings().Mh6HeightAdjustment;
				}
				if (ExpansionUh1h.Cast(Heli)){
					heightAdjust = heliPadPosition[1] + GetSnapHeliSettings().Uh1hHeightAdjustment;
				}
				if (ExpansionMerlin.Cast(Heli)){
					heightAdjust = heliPadPosition[1] + GetSnapHeliSettings().MerlinHeightAdjustment;
				}
				vector newOrientation = Vector(heliOrientation[0], heliPadOrientation[1], heliPadOrientation[2]);
				vector newPosition = Vector(heliPadPosition[0], heightAdjust, heliPadPosition[2]);
				Heli.SetOrientation( newOrientation );
				Heli.SetPosition( newPosition );
				
				SetVelocity(Heli, Vector(0,0,0));
				dBodyActive( Heli, ActiveState.ALWAYS_ACTIVE );
				dBodyDynamic( Heli, true );
				#ifdef DF_REDUCEVEHICLEDAMAGE
					Heli.rvd_delayedVectorUpdate();
				#endif
				Heli.SetSynchDirty();
				m_AwaitingSnap = false;
				SetSynchDirty();
			}
		}
	}
}