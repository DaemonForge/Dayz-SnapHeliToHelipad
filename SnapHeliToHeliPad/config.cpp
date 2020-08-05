class CfgPatches
{
	class SnapHeliToHeliPad
	{
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DayZExpansion_Scripts"
		};
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
	    dependencies[]={ "World", "Mission"};
	    class defs
	    {
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