#pragma once 
#include "EditorModes.h"
#include "EdMode.h"
#include "../OpenDriveRoadEd.h"

class FOpenDRIVEEditorMode : public FEdMode
{
public :
	const static FEditorModeID EM_RoadMode;

	FOpenDRIVEEditorMode();

	virtual void Enter() override;
	virtual void Exit() override;

	inline bool GetHasBeenLoaded() const { return bHasBeenLoaded; };

	void Reset();

	void Generate();

	inline TArray<AOpenDriveRoadEd*> GetRoads() const { return Roads; };

	~FOpenDRIVEEditorMode();

	void OnMapOpenedCallback(const FString& MapName, bool bLoadAsTemplate);

protected :

	bool bHasBeenLoaded = false;

	void LoadRoads();

	void SetRoadsVisibility(bool bIsVisible);
	
	TArray<AOpenDriveRoadEd*> Roads;

private :

	FDelegateHandle MapOpenedDelegateHandle;

	bool bIsMapOpening;
};