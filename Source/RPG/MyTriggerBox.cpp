// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "RPGCharacter.h"

#include "Kismet/GameplayStatics.h"

AMyTriggerBox::AMyTriggerBox()
{
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
}

void AMyTriggerBox::BeginPlay()
{
    Super::BeginPlay();

#if WITH_EDITOR
    if(showDebug)
    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), DebugColorBox, true, 999, 0, 5);
#endif // WITH_EDITOR

}

void AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && (OtherActor->ActorHasTag(FName(TEXT("Player")))))
    {
        ARPGCharacter* character = Cast<ARPGCharacter>(OtherActor);
        if (character)
        {

#if WITH_EDITOR
            if (GEngine)
            {
                //GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
                //GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Magenta, FString::Printf(TEXT("Overlapped Actor = %s"), *OverlappedActor->GetName()));
            }
#endif
        }

        FLatentActionInfo LatentInfo;

        if (LevelToLoad != "")
        {
            UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, LatentInfo);
        }

        if (LevelToUnLoad != "")
        {
            UGameplayStatics::UnloadStreamLevel(this, LevelToUnLoad, LatentInfo, true);
        }
    }
}

void AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {
            //GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
        }
    }
}


