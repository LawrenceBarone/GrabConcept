// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"

AMyTriggerBox::AMyTriggerBox() {
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
}

void AMyTriggerBox::BeginPlay() {
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}

void  AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		print("Overlap Begin");
		printf("Overlapped Actor = %s", *OverlappedActor->GetName());
	}
}

void  AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		print("Overlap Has Ended");
		printf("Overlapped Actor = %s", *OtherActor->GetName());
	}
}



