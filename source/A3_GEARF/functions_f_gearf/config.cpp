class CfgPatches {

	class functions_f_gearf {
		author = "Flax";
		name = "Gear Functions - Functions";
		requiredAddons[] = {};
		requiredVersion = 0.100000;
		units[] = {};
		weapons[] = {};
	};
};

class cfgFunctions
{
	class GEARF
	{
		class vectorFunctions
		{
			file="\A3_GEARF\functions_f_gearf\Vectors";
			class rotateObject {}; // [object, [x,y,z]] call GEARF_fnc_rotateObject
		};
		class helmetFunctions
		{
			file="\A3_GEARF\functions_f_gearf\Helmet";
			class slingHelmet {}; // [unit, "left/right"] call GEARF_fnc_slingHelmet
			class unslingHelmet {}; // [unit] call GEARF_fnc_unslingHelmet
			class hideSlungHelmet {}; // [unit, true/false] call GEARF_fnc_hideSlungHelmet
		};
	};
};


class CfgVehicles {
  /*extern*/ class Man;

	// Class for ACE Interactions to do with Helmet Slinging
  class CAManBase: Man {
    class ACE_SelfActions {
      class ACE_Equipment {
        class slingHelmet {
					displayName = "Sling Helmet"
					icon = "\A3_GEARF\data_f_gearf\UI_icons\helmet_ca.paa";
          priority = 3;
					condition = "!(_player getVariable ['GEARF_HelmetAttached', false])";

					class slingLeft {
						displayName = "Sling Left";
	          icon = "\A3_GEARF\data_f_gearf\UI_icons\helmet_ca.paa";
	          priority = 3;
	          condition = "!(_player getVariable ['GEARF_HelmetAttached', false])";
	          statement = "[_player, 'left'] call GEARF_fnc_slingHelmet";
					};
					class slingRight {
						displayName = "Sling Right";
	          icon = "\A3_GEARF\data_f_gearf\UI_icons\helmet_ca.paa";
	          priority = 3;
	          condition = "!(_player getVariable ['GEARF_HelmetAttached', false])";
	          statement = "[_player, 'right'] call GEARF_fnc_slingHelmet";
					};
        };
				class unslingHelmet {
					displayName = "Unsling Helmet";
					icon = "\A3_GEARF\data_f_gearf\UI_icons\helmet_ca.paa";
					priority = 3;
					condition = "_player getVariable ['GEARF_HelmetAttached', false]";
					statement = "[_player] call GEARF_fnc_unslingHelmet";
				};
      };
    };
		// Class for event handles that manage variables for checking helmet is attached and storing helmet class and hiding/ showing a slung helmet in a GetIn GetOut event.
    class EventHandlers {
      init = "(_this select 0) setVariable ['GEARF_HelmetAttached', false]; (_this select 0) setVariable ['GEARF_HelmetAttachedClass',''];";
			killed = "(_this select 0) setVariable ['GEARF_HelmetAttached', false]; (_this select 0) setVariable ['GEARF_HelmetAttachedClass',''];";
			getInMan = "[(_this select 0), true] call GEARF_fnc_hideSlungHelmet";
			getOutMan = "[(_this select 0), false] call GEARF_fnc_hideSlungHelmet;";
    };
  };
};
