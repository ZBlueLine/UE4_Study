// Copyright Epic Games, Inc. All Rights Reserved.

#include "hit_box.h"
#include "hit_boxGameModeBase.h"

void Ahit_boxGameModeBase::StartPlay()
{
    Super::StartPlay();

    if (GEngine)
    {
        // ��ʾ������Ϣ���롣 
        // -1"��"ֵ���׸�������˵������������»�ˢ�´���Ϣ��
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
    }
}