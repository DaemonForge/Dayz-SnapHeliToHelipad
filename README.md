# Dayz-SnapHeliToHeliPad
 
This mod allows you to snap Helis to heli pads with a config file

```javascript
{
	"ConfigVersion": "2",    // This is the config version do not change this is just to allow me to auto update the config when needed
	"EnableOnHeliPad": 1,    // 1 Enabled / 0 Disabled when enabled the snap action will happen at every restart and one placement of the helipad
	"EnableSnapHeliAction": 0,   //1 Enabled / 0 Disabled when Enabled it will allow players to interact with the heli pad to snap the heli to it
	"Radius": 18,                //This is the radius to search for a heli to snap the smaller the better on performance
	"Mh6HeightAdjustment": 0.5,  //This is the height at which the heli will be TP above the heli pad (Note: the Mh6 game postion is the bottom of the heli)
	"Uh1hHeightAdjustment": 3.5,  //This is the height at which the heli will be TP above the heli pad (Note: the UH1h game postion is the rotors of the heli)
	"MerlinHeightAdjustment": 4.5,  //This is the height at which the heli will be TP above the heli pad (Note: the Merlin game postion is the rotors of the heli)
	"OtherHeightAdjustment": 3.6,  //This is for any modded helis
    "VirtualHelipads": [   //This is an array of the X Y Z cordinates for virtual helipads
        {
            "X": 4169.21,
            "Y": 338.415,
            "Z": 10990.3
        },
        {
            "X": 2610.09,
            "Y": 21.7514,
            "Z": 1306.52
        },
        {
            "X": 1689.94,
            "Y": 451.739,
            "Z": 14343.3
        },
        {
            "X": 4096.73,
            "Y": 342.045,
            "Z": 10652.3
        },
        {
            "X": 8007.44,
            "Y": 342.699,
            "Z": 14627.9
        },
        {
            "X": 504.444,
            "Y": 424.995,
            "Z": 11237.2
        }
    ]
}
```

### Repacking/Building from Source Code Rules
For anyone interested in repacking please read all this
- 1st I heavily discourage Repacking/Building from my source code, as it would greatly impact your ability to receive feature updates and bug fixes
- 2nd I will not support any repacks if its is causing conflict that I can't reproduce with the my published mod 
- 3rd YOU MUST PROVIDE CREDIT on the steam page and you must link to the Orginal Mod or the Source Code
- 4th Any repacks or builds can only be for personal use no redistributing my mod for public use, should only be for your own servers and players and you must be able to enfore this
- 5th Please ask for permission prior to repacking, almost all request will be approved as long as you have a valid reason to repack
- 6th Also note that the Source Code is the activly developing version so it may not work as it sits here right now so just be warnned.
- 7th Must include the NOTICE file in side the mod with out modification to my text
