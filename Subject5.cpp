#include "MyActor.h"
#include "Engine/Engine.h"
// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // 시작 좌표는 (0, 0)
    CurrentLocation = FVector2D(0, 0);
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    // 시작 좌표는 (0, 0)
    CurrentLocation = FVector2D(0, 0);
    // 게임 시작 시 Move 함수 호출
    Move();
}
// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
void AMyActor::Move()
{
    for (int32 i = 0; i < 10; ++i)
    {
        // Step 함수로 X, Y 이동 값 각각 구하고
        int32 StepX = Step();
        int32 StepY = Step();
        // 현재 좌표에 이동 결과를 더해서 새로운 좌표를 구함
        CurrentLocation.X += StepX;
        CurrentLocation.Y += StepY;
        // UE_LOG로 좌표 출력
        UE_LOG(LogTemp, Log, TEXT("Step %d: Current Location: (%f, %f)"), i + 1, CurrentLocation.X, CurrentLocation.Y);
    }
}
// Step 함수는 0 또는 1을 랜덤으로 반환
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);  // 0 또는 1을 반환
}