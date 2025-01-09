#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
UCLASS()
class SUBJECT_API AMyActor : public AActor
{
    GENERATED_BODY()
public:
    // Sets default values for this actor's properties
    AMyActor();
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    // 이동 함수
    void Move();
private:
    // 좌표 변수
    FVector2D CurrentLocation;
    // 이동 범위 (0 혹은 1을 반환)
    int32 Step();
};