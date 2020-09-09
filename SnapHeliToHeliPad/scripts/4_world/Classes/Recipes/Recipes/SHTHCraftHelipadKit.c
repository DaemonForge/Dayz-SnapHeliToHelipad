class SHTHCraftHelipadKit extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Craft Helipad Kit";
		
		m_IsInstaRecipe = false;
		m_AnimationLength = 1.5;
		m_Specialty = -0.02;
		
		//! Conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;
		
		m_MinQuantityIngredient[0] = 1;
		m_MaxQuantityIngredient[0] = -1;
		
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;
		
		m_MinQuantityIngredient[1] = 1;
		m_MaxQuantityIngredient[1] = -1;
		
		//----------------------------------------------------------------------------------------------------------------------
		
		//! Ingredient 2
		InsertIngredient(0, "LongWoodenStick"); //! You can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1; 
		m_IngredientAddQuantity[0] = -1;
		m_IngredientDestroy[0] = true;
		m_IngredientUseSoftSkills[0] = false;
		
		//! Ingredient 2
		InsertIngredient(1, "Rope"); //! You can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = -1;
		m_IngredientDestroy[1] = true;
		m_IngredientUseSoftSkills[1] = false;
		
		//----------------------------------------------------------------------------------------------------------------------
		
		//! Result
		AddResult("ExpansionHelipadKit"); //! Add results here

		m_ResultSetFullQuantity[0] = true;
		m_ResultSetQuantity[0] = 1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		bool canCraft = GetSnapHeliSettings().CanCraftHeliPadKit;

		if ( canCraft )
		{
			return super.CanDo( ingredients, player );
		}

		return false;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight) //! Gets called upon recipe's completion
	{
		Debug.Log( "Recipe Do method called", "recipes" );
	}
}