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

    // �̵� �Լ�
    void Move();

private:
    // ��ǥ ����
    FVector2D CurrentLocation;

    // �̵� ���� (0 Ȥ�� 1�� ��ȯ)
    int32 Step();

    // �Ÿ� ��� �Լ�
    float Distance(FVector2D first, FVector2D second);

    // �̺�Ʈ �߻� ���θ� �����ϰ� ��ȯ
    bool ShouldTriggerEvent();

    // �̺�Ʈ ��� �Լ�
    void createEvent();
};