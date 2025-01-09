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
    CurrentLocation = FVector2D(0, 0);  // 초기 좌표 (0, 0)

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
    FVector2D PreviousLocation = CurrentLocation;
    int32 totDist = 0;  // 총 이동 거리 (int32로 변경)
    int evCnt = 0;  // 이벤트 발생 횟수

    for (int32 i = 0; i < 10; ++i)
    {
        // Step 함수로 X, Y 이동 값 각각 구하고
        int32 StepX = Step();
        int32 StepY = Step();

        // 현재 좌표에 이동 결과를 더해서 새로운 좌표를 구함
        CurrentLocation.X += StepX;
        CurrentLocation.Y += StepY;

        // 거리 계산
        float Dist = Distance(PreviousLocation, CurrentLocation);
        totDist += Dist;

        // 이벤트 발생 여부 체크
        bool bEventTriggered = ShouldTriggerEvent();
        if (bEventTriggered)
        {
            evCnt++;  // 이벤트 발생 횟수 증가
            UE_LOG(LogTemp, Log, TEXT("Step %d: Event Triggered!"), i + 1);
        }

        // 이전 좌표를 현재 좌표로 갱신
        PreviousLocation = CurrentLocation;

        // UE_LOG로 좌표 출력 및 거리 출력
        UE_LOG(LogTemp, Log, TEXT("Step %d: Current Location: (%f, %f), Distance from last step: %f"), i + 1, CurrentLocation.X, CurrentLocation.Y, Dist);
    }

    // 10회 이동 후 총 이동 거리 및 이벤트 발생 횟수 출력
    createEvent();
}

// Step 함수는 0 또는 1을 랜덤으로 반환
int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1);  // 0 또는 1을 반환
}

// 거리 계산 함수 (피타고라스의 정리)
float AMyActor::Distance(FVector2D first, FVector2D second)
{
    return FMath::Sqrt(FMath::Pow(second.X - first.X, 2) + FMath::Pow(second.Y - first.Y, 2));
}

// 50% 확률로 이벤트 발생 여부를 반환
bool AMyActor::ShouldTriggerEvent()
{
    return FMath::RandRange(0, 1) == 1;  // 50% 확률로 true 반환
}

// 이벤트가 발생하면 출력되는 함수
void AMyActor::createEvent()
{
    // 1부터 30까지 숫자 출력, 3, 6, 9에는 "짝" 출력
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
            UE_LOG(LogTemp, Warning, TEXT("짝"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }
}