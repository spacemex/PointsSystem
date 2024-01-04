/*
 * Copyright (c) 2023 Space_Mex
 * 
 * All rights reserved.
 * 
 * This file is part of the PointsSystem Plugin.
 * Unauthorized copying of this file, via any medium, is strictly prohibited.
 * Proprietary and confidential.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PointsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POINTSYSTEM_API UPointsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPointsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	//Variables
	
	/**This Is The Starting Points What Your Default Points When The Game Begins (Default is 500)*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PointsSystem | Default | Points")
	int StartingPoints = 500;

	/**This Is Where Your Total Points Are Stored (Default is StartingPoints)*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PointsSystem | Default | Points")
	int Points = StartingPoints;

	//Functions

	/**Set The Points variable (Setter)*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystem | Setters")
	void SetTotalPoints(int NewPoints){Points = NewPoints;}

	/**Set The Starting Points (Setter)*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystem | Setters")
	void SetStartingPoints(int NewPoints){StartingPoints = NewPoints;}

	/**Get The Current Total Points (Getter)*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystem | Getters")
	int GetTotalPoints(){return Points;}

	/**Get Starting Points (Getter)*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystem | Getters")
	int GetStartingPoints(){return StartingPoints;}

	/**Add Points To Current Points*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystem | Adders")
	void AddPoints(int Value){Points += Value;}

	/**Remove Points From Current Points*/
	UFUNCTION(BlueprintCallable, Category = "PointsSystme | Removers")
	void RemovePoints(int Value){if (Points > 0){Points = FMath::Clamp(Points - Value,0, MAX_int32);}}

	/**Has Enough Point*/
	UFUNCTION(BlueprintCallable, Category = "PointsSytem | Checks")
	bool HasEnoughPoints(int Value){if (Points >= Value){return true;}return false;}
};
