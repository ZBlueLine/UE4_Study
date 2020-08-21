// Fill out your copyright notice in the Description page of Project Settings.

#include "hit_box.h"
#include "BoxCharacter.h"

// Sets default values
ABoxCharacter::ABoxCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoxCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("we are using FPScharacter"));
}

// Called every frame
void ABoxCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoxCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ����"�ƶ�"�󶨡�
	PlayerInputComponent->BindAxis("MoveX", this, &ABoxCharacter::MoveX);
	PlayerInputComponent->BindAxis("MoveY", this, &ABoxCharacter::MoveY);

	PlayerInputComponent->BindAxis("Turn", this, &ABoxCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABoxCharacter::AddControllerPitchInput);

}

void ABoxCharacter::MoveX(float Value)
{
	// ��ȷ�ĸ�������"ǰ��"������¼�����ͼ��˷����ƶ���
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value, false);
}

void ABoxCharacter::MoveY(float Value)
{
	// ��ȷ�ĸ�������"����"������¼�����ͼ��˷����ƶ���
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}
