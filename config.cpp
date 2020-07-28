class CfgPatches
{
	class SnapHeliToHeliPad
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DayZExpansion_Scripts",

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
        extra=0;
        type="mod";
	    dependencies[]={ "World", "Mission"};
	    class defs
	    {
			class worldScriptModule
            {
                value="";
                files[]={ 
					"SnapHeliToHeliPad/scripts/4_World" 
				};
            };
			
	        class missionScriptModule
            {
                value="";
                files[]={
					"SnapHeliToHeliPad/scripts/5_Mission" 
				};
            };
        };
    };
};