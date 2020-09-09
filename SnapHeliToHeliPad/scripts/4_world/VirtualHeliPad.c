class VirtualHelipad 
{
	float X = 0; 
	float Y = 0;
	float Z = 0;;
	
	void VirtualHelipad(ref VHelipad vPad)
	{
		X = vPad.X;
		Y = vPad.Y;
		Z = vPad.Z;
	}
	
	void Init(){
		if(GetGame().IsServer()){
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.FindClosestHeli, GetSnapHeliSettings().InitSnapDelaySec * 1000, false, NULL );
		}
	}
	
	vector GetPosition(){
		return Vector( X, Y, Z );
	}
	
	vector GetOrientation(){
		return Vector( 0, 0, 0 );
	}
	
	void FindClosestHeli(){
		if(GetGame().IsServer()){
			float closestDisRef = GetSnapHeliSettings().Radius + 1;
			float closestDisDefault = closestDisRef;
			ExpansionHelicopterScript closestHeliRef; 
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
						closestHeliRef = ExpansionHelicopterScript.Cast(heli);
					}
				}
			}
			
			if (closestHeliRef && closestDisRef != closestDisDefault)
			{
				Print( "[SnapHeliToHeliPad] VirtualHelipad at " + GetPosition() + " Found " + closestHeliRef.GetType() +  " at " + closestHeliRef.GetPosition());
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.SnapHeliToHeliPad, 1200, false, closestHeliRef ); //Find calling twice make it more stable
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.SnapHeliToHeliPad, 1250, false, closestHeliRef );
			}
		}
	}
	
	void SnapHeliToHeliPad(ExpansionHelicopterScript heli){
		ExpansionHelicopterScript Heli = ExpansionHelicopterScript.Cast(heli);
		if( Heli ){ //Just a double checkk to be safe :)
			if (!Heli.EngineIsOn()){
				SetVelocity(Heli, vector.Zero);
				dBodyActive( Heli, ActiveState.ALWAYS_ACTIVE );
				dBodyDynamic( Heli, true );
				vector heliPadOrientation = GetOrientation();
				vector heliPadPosition = GetPosition();
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
				vector heliOrientation = Heli.GetOrientation();
				vector newOrientation = Vector(heliOrientation[0], heliPadOrientation[1], heliPadOrientation[2]);
				vector newPosition = Vector(heliPadPosition[0], heightAdjust, heliPadPosition[2]);
				Heli.SetOrientation( newOrientation );
				Heli.SetPosition( newPosition );
				
				SetVelocity(Heli, vector.Zero);
				dBodyActive( Heli, ActiveState.ALWAYS_ACTIVE );
				dBodyDynamic( Heli, true );
				#ifdef DF_REDUCEVEHICLEDAMAGE
					Heli.rvd_delayedVectorUpdate();
				#endif
				Heli.SetSynchDirty();
			}
		}
	}
};