#include "MyActor.h"
#include "Engine/Engine.h"
// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // ���� ��ǥ�� (0, 0)
    CurrentLocation = FVector2D(0, 0);
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    // ���� ��ǥ�� (0, 0)
    CurrentLocation = FVector2D(0, 0);
    // ���� ���� �� Move �Լ� ȣ��
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
        // Step �Լ��� X, Y �̵� �� ���� ���ϰ�
        int32 StepX = Step();
        int32 StepY = Step();
        // ���� ��ǥ�� �̵� ����� ���ؼ� ���ο� ��ǥ�� ����
        CurrentLocation.X += StepX;
        CurrentLocation.Y += StepY;
        // UE_LOG�� ��ǥ ���
        UE_LOG(LogTemp, Log, TEXT("Step %d: Current Location: (%f, %f)"), i + 1, CurrentLocation.X, CurrentLocation.Y);
    }
}
// Step �Լ��� 0 �Ǵ� 1�� �������� ��ȯ
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);  // 0 �Ǵ� 1�� ��ȯ
}