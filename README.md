# MuClientTools by VD (Vic)
Mu Client Tools (Season 13e1)  
This project is using test files obtained from client Mu Online Season 13 ep.1 (Webzen).  

```cpp
/*
It might (or not) work for files from older/newer version. 
The ones want to modify the tools in order to fit with their data files should check:
	_wkey : used for calculating CRC of a data file.
	_xor3key : used for basic Dec/Enc data.
	_LANG_ZIP_PASSWORD_ : used for (un)zipping Lang.mpr file. 
		Note: For some older version, the Lang.mpr can be open (w/o password) 
		by zip tools such as: Winrar, 7z,...
	Client Data Struct: Sometime, WZ might add a few bytes to the exsiting. 
C/C++ reversing skills is a plus to see the changes in thier game client.
*/
```

### PROJECT'S CHECKLIST:

### Data and Config Files: 68% (30 / 44)  
:heavy_check_mark:	1.	Lang.mpr  
  
```cpp
/*
(7z.dll is required for (un)zipping)
The file is an archive of most newly updated data files as listed below:
4ThTreeData.txt					4ThTreeSideOption.txt			4ThTreeSkillTooltip.txt
ArcaBattleBootyMix.txt				ArcaBattleScript.txt			AttributeVariation.txt
BonusExp.txt					BuffEffect.txt				CharacterInfoSetup.txt
Credit.txt					Dialog(kor).txt				ElementalMixList.txt
Filter(kor).txt					FilterName(kor).txt			Gate.txt
GradedOption.txt				GuideQuest.txt				GuideQuestString(Kor).txt
HuntingRecord.txt				ItemLevelTooltip.txt			ItemTRSData.txt
LabyrinthOfDimensionInfo.txt			MasteryItemBonusOption.txt		MBoxShop(kor).txt
Mixslotframe.txt				movereq(kor).txt			MuunEffectInfo.txt
npcName(kor).txt				PentagramJewelOptionValue.txt		PentagramOption.txt
SeedsphereUpgrade.txt				Skill(kor).txt				SkillRequire.txt
Slide(kor).txt					SocketitemUpgrade.txt			SpellStone.txt
Text(kor).txt					WingAttribute.txt
RenderingData/EnchantEffect.txt
EffectInfo/EffectInfoxxx.txt
*/
```
  
:heavy_check_mark:	2.	Item.bmd  
:heavy_check_mark:	3.	ExcellentCommonOption.bmd  
:heavy_check_mark:	4.	ExcellentWingOption.bmd  
:heavy_check_mark:	5.	FormulaData.bmd  
:heavy_check_mark:	6.	PentagramMixNeedSource.bmd  
:heavy_check_mark:	7.	MuunOption.bmd  
:heavy_check_mark:	8.	MuunInfo.bmd  
:heavy_check_mark:	9.	MuunTooltipInfo.bmd  
:heavy_check_mark:	10.	MuunExchange.bmd  
:heavy_check_mark:	11.	StatOption.bmd  
:heavy_check_mark:	12.	StatOptionText.bmd  
:heavy_check_mark:	13.	Quest.bmd  
:heavy_check_mark:	14.	SocketItem.bmd  
:heavy_check_mark:	15.	PlayGuide.bmd  
:heavy_check_mark:	16.	EvolutionMonsterBox.bmd  
:heavy_check_mark:	17.	MuRummyOption.bmd  
:heavy_check_mark:	18.	MuRummyCard.bmd  
:heavy_check_mark:	19.	MuRummySlot.bmd  
:heavy_check_mark:	20.	ServerList.bmd  
:heavy_check_mark:	21.	MapCharacters.bmd  
:heavy_check_mark:	22.	ItemSetType.bmd  
:heavy_check_mark:	23.	ItemSetOption.bmd  
:heavy_check_mark:	24.	ItemSetOptionText.bmd  
:heavy_check_mark:	25.	MonsterSkill.bmd  
:heavy_check_mark:	26.	MasterSkillTreeData.bmd  
:heavy_check_mark:	27.	MasterSkillTooltip.bmd  
:heavy_check_mark:	28.	NPCDialogue.bmd  
:heavy_check_mark:	29.	QuestProgress.bmd  
:heavy_check_mark:	30.	QuestWords.bmd  
  
31.	SkillTooltipText.bmd  
32.	ItemAddOption.bmd  
33.	JewelOfHarmonyOption.bmd  
~~34.	JewelOfHarmonySmelt.bmd~~  
34.	Mix.bmd  
35.	itemtooltip.bmd  
36.	itemtooltiptext.bmd  
37.	petdata.bmd  
38.	pet.bmd  
39.	InfoTooltip.bmd  
40.	InfoTooltipText.bmd  
41.	RuudShopViewInfo.bmd  
42.	helpdata.bmd  
43.	MuunRenderInfo.bmd  
44.	MuunMeshInfo.bmd  

### Image, 3D Model, and Interface Files: 0% (0 / 5)  
	1.	OZJ	(-> .jpg)  
	2.	OZT	(-> .tga)  
	3.	OZD	(-> .dds)  
	4.	BMD	(-> .smd)  
	5.	OZG	(-> .gfx)  

