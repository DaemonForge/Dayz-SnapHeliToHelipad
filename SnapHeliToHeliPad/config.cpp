class CfgPatches
{
	class SnapHeliToHeliPad
	{
		requiredVersion=0.1;
	};
};
class CfgMods
{
	class SnapHeliToHeliPad
	{
		dir="SnapHeliToHeliPad";
        name="SnapHeliToHeliPad";
        credits="DaemonForge";
        author="DaemonForge";
        authorID="0";
        version="0.1";
        type="mod";
	    dependencies[]={ "Game", "World", "Mission"};
	    class defs
	    {
			class gameScriptModule
            {
				value = "";
                files[]={
					"SnapHeliToHeliPad/scripts/3_Game"
					};
            };
			
			class worldScriptModule
            {
                files[]={ 
					"SnapHeliToHeliPad/scripts/4_World" 
				};
            };
			
	        class missionScriptModule
            {
                files[]={
					"SnapHeliToHeliPad/scripts/5_Mission" 
				};
            };
        };
    };
};