#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "MYPhysicalMaterial.generated.h"

UCLASS()
class MINYEOL_API UMYPhysicalMaterial : public UPhysicalMaterial
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PhysicalMaterial)
	class USoundBase* FootstepSound = nullptr;
};
