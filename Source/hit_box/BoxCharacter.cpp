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

	// 设置"移动"绑定。
	PlayerInputComponent->BindAxis("MoveX", this, &ABoxCharacter::MoveX);
	PlayerInputComponent->BindAxis("MoveY", this, &ABoxCharacter::MoveY);

	PlayerInputComponent->BindAxis("Turn", this, &ABoxCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABoxCharacter::AddControllerPitchInput);

}

void ABoxCharacter::MoveX(float Value)
{
	// 明确哪个方向是"前进"，并记录玩家试图向此方向移动。
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value, false);
}

void ABoxCharacter::MoveY(float Value)
{
	// 明确哪个方向是"向右"，并记录玩家试图向此方向移动。
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}
