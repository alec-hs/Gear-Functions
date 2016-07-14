_unit = _this select 0;
_side = _this select 1;
_helmetAttached = _unit getVariable ["GEARF_HelmetAttached", false];

if (headgear _unit == "")  then {
  _helmet = _unit getVariable ["GEARF_HelmetAttachedClass", false];
  _unit addHeadgear _helmet;
  _unit setVariable ["GEARF_HelmetAttached", false];
  {
      if (typeOf _x == "GroundWeaponHolder") then {deleteVehicle _x};
  } forEach (attachedObjects _unit);
} else {
  hint "Remove headger before wearing helmet.";
};
