#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentLocation = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    CurrentLocation = FVector2D(0, 0);  // �ʱ� ��ǥ (0, 0)

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
    FVector2D PreviousLocation = CurrentLocation;
    int32 totDist = 0;  // �� �̵� �Ÿ� (int32�� ����)
    int evCnt = 0;  // �̺�Ʈ �߻� Ƚ��

    for (int32 i = 0; i < 10; ++i)
    {
        // Step �Լ��� X, Y �̵� �� ���� ���ϰ�
        int32 StepX = Step();
        int32 StepY = Step();

        // ���� ��ǥ�� �̵� ����� ���ؼ� ���ο� ��ǥ�� ����
        CurrentLocation.X += StepX;
        CurrentLocation.Y += StepY;

        // �Ÿ� ���
        float Dist = Distance(PreviousLocation, CurrentLocation);
        totDist += Dist;

        // �̺�Ʈ �߻� ���� üũ
        bool bEventTriggered = ShouldTriggerEvent();
        if (bEventTriggered)
        {
            evCnt++;  // �̺�Ʈ �߻� Ƚ�� ����
            UE_LOG(LogTemp, Log, TEXT("Step %d: Event Triggered!"), i + 1);
        }

        // ���� ��ǥ�� ���� ��ǥ�� ����
        PreviousLocation = CurrentLocation;

        // UE_LOG�� ��ǥ ��� �� �Ÿ� ���
        UE_LOG(LogTemp, Log, TEXT("Step %d: Current Location: (%f, %f), Distance from last step: %f"), i + 1, CurrentLocation.X, CurrentLocation.Y, Dist);
    }

    // 10ȸ �̵� �� �� �̵� �Ÿ� �� �̺�Ʈ �߻� Ƚ�� ���
    createEvent();
}

// Step �Լ��� 0 �Ǵ� 1�� �������� ��ȯ
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);  // 0 �Ǵ� 1�� ��ȯ
}

// �Ÿ� ��� �Լ� (��Ÿ����� ����)
float AMyActor::Distance(FVector2D first, FVector2D second)
{
    return FMath::Sqrt(FMath::Pow(second.X - first.X, 2) + FMath::Pow(second.Y - first.Y, 2));
}

// 50% Ȯ���� �̺�Ʈ �߻� ���θ� ��ȯ
bool AMyActor::ShouldTriggerEvent()
{
    return FMath::RandRange(0, 1) == 1;  // 50% Ȯ���� true ��ȯ
}

// �̺�Ʈ�� �߻��ϸ� ��µǴ� �Լ�
void AMyActor::createEvent()
{
    // 1���� 30���� ���� ���, 3, 6, 9���� "¦" ���
    for (int i = 1; i <= 30; ++i)
    {
        FString Number = FString::FromInt(i);
        bool bIsClap = false;

        for (TCHAR Char : Number)
        {
            if (Char == '3' || Char == '6' || Char == '9')
            {
                bIsClap = true;
                break;
            }
        }

        if (bIsClap)
        {
            UE_LOG(LogTemp, Warning, TEXT("¦"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }
}