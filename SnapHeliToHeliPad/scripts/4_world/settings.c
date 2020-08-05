static string SnapHeliPATH = "$profile:\\SnapHeli.json";
ref SnapHeliSettings m_SnapHeliSettings
class SnapHeliSettings
{ 
	//Default Values
	string ConfigVersion = "2";
	
	bool EnableOnHeliPad = true;
	bool EnableSnapHeliAction = false;
	
	float Radius = 18;
	
	ref array< ref VirtualHelipad > VirtualHelipads = new ref array< ref VirtualHelipad >;
	
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
			if ( ConfigVersion != "2"){
				EnableSnapHeliAction = false;
				
				Mh6HeightAdjustment = 0.5;
				Uh1hHeightAdjustment = 3.5;
				MerlinHeightAdjustment = 4.7;
				OtherHeightAdjustment = 3.7;
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
		VirtualHelipad temp = new ref VirtualHelipad(x, y, z);
		VirtualHelipads.Insert(temp);
	}
}

//Helper function to return Config
static ref SnapHeliSettings GetSnapHeliSettings()
{
	if (!m_SnapHeliSettings)
	{
		m_SnapHeliSettings = new SnapHeliSettings;
		m_SnapHeliSettings.Load();
	}
	return m_SnapHeliSettings;
}
