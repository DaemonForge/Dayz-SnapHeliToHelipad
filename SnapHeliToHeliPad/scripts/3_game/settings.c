ref SnapHeliSettings m_SnapHeliSettings
class SnapHeliSettings
{ 
	protected static string SnapHeliPATH = "$profile:\\SnapHeli.json";
	
	//Default Values
	string ConfigVersion = "3";
	
	bool EnableOnHeliPad = true;
	bool EnableSnapHeliAction = false;
	bool CanCraftHeliPadKit = false;
	float InitSnapDelaySec = 4.5;
	float Radius = 18;
	
	ref array< ref VHelipad > VirtualHelipads = new ref array< ref VHelipad >;
	
	float Mh6HeightAdjustment = 0.3;
	float Uh1hHeightAdjustment = 3.4;
	float MerlinHeightAdjustment = 4.2;
	float OtherHeightAdjustment = 3.5;
	
	void SnapHeliSettings(){
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(SnapHeliPATH)) //If config exist load File
		{
	        JsonFileLoader<SnapHeliSettings>.JsonLoadFile(SnapHeliPATH, this);
			if ( ConfigVersion != "3"){
				ConfigVersion = "3";
				InitSnapDelaySec = 4.5;
				CanCraftHeliPadKit = false;
				JsonFileLoader<SnapHeliSettings>.JsonSaveFile(SnapHeliPATH, this);
			}
		}else{ //File does not exist create file
			AddVirtualHelipad(4169.207031, 338.414795, 10990.304688);
			AddVirtualHelipad(2610.090576, 21.751432, 1306.517334);
			AddVirtualHelipad(1689.941284, 451.738586, 14343.285156);
			AddVirtualHelipad(4096.730957, 342.045197, 10652.285156);
			AddVirtualHelipad(8007.443848, 342.698883, 14627.948242);
			AddVirtualHelipad(504.444275, 424.994934, 11237.21875);
			JsonFileLoader<SnapHeliSettings>.JsonSaveFile(SnapHeliPATH, this);
		}
	}
	
	void AddVirtualHelipad( float x, float y, float z){
		VHelipad temp = new ref VHelipad(x, y, z);
		VirtualHelipads.Insert(temp);
	}
};

class VHelipad 
{
	float X = 0; 
	float Y = 0;
	float Z = 0;
	
	void VHelipad( float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	
};

//Helper function to return Config
static ref SnapHeliSettings GetSnapHeliSettings()
{
	if (!m_SnapHeliSettings)
	{
		m_SnapHeliSettings = new SnapHeliSettings;
		m_SnapHeliSettings.Load();
	}
	return m_SnapHeliSettings;
};
