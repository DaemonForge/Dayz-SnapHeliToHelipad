class ActionSnapHeliToHeliPad extends ActionInteractBase
{

	void ExpansionActionOpenTraderMenu()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}

	override string GetText()
	{
		return "Snap Heli";
	}

	override typename GetInputType()
	{
		return InteractActionInput;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ExpansionHelipad helipad = ExpansionHelipad.Cast( target.GetObject() );
		if ( helipad )
		{
			if (!helipad.IsAwaitingSnap()){
				return GetSnapHeliSettings().EnableSnapHeliAction;
			}
		}
		
		return false;
	}
	
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );
		ExpansionHelipad helipad = ExpansionHelipad.Cast(action_data.m_Target.GetObject());
		if (helipad){
			helipad.ActionFindClosestHeli();
		}
	}
};