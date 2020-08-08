// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverFunctionLibrary.h"

#include "JoyConDriverModule.h"
#include "Features/IModularFeatures.h"

void UJoyConDriverFunctionLibrary::ResumeJoyConConnection(bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().ResumeJoyConConnection();
		break;
	}
}

void UJoyConDriverFunctionLibrary::ConnectJoyCon(const FJoyConInformation JoyConInformation, const bool UseImu, const bool UseLocalize, bool& Success, int& ControllerIndex, const float Alpha) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().ConnectJoyCon(JoyConInformation, UseImu, UseLocalize, Alpha, ControllerIndex);
		break;
	}
}

void UJoyConDriverFunctionLibrary::AttachJoyCon(const int ControllerIndex, const int GripIndex, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().AttachJoyCon(ControllerIndex, GripIndex);
		break;
	}
}

void UJoyConDriverFunctionLibrary::DisconnectJoyCon(const int ControllerIndex, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().DisconnectJoyCon(ControllerIndex);
		break;
	}
}

void UJoyConDriverFunctionLibrary::DetachJoyCon(const int ControllerIndex, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().DetachJoyCon(ControllerIndex);
		break;
	}
}

void UJoyConDriverFunctionLibrary::SearchForJoyCons(TArray<FJoyConInformation>& JoyCons) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		TArray<FJoyConInformation>* Data = JoyConInputApi->Get().SearchForJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
			break;
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
		break;
	}
}

void UJoyConDriverFunctionLibrary::GetAttachedJoyCons(TArray<FJoyConInformation>& JoyCons) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	JoyCons = TArray<FJoyConInformation>();
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		TArray<FJoyConInformation>* Data = JoyConInputApi->Get().GetAttachedJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
			break;
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
		break;
	}
}

void UJoyConDriverFunctionLibrary::GetConnectedJoyCons(TArray<FJoyConInformation>& JoyCons) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	JoyCons = TArray<FJoyConInformation>();
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		TArray<FJoyConInformation>* Data = JoyConInputApi->Get().GetConnectedJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
			break;
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
		break;
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConAccelerometer(const int ControllerIndex, bool& Success, FVector& Accelerometer) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	Accelerometer = FVector::ZeroVector;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().GetJoyConAccelerometer(ControllerIndex, Accelerometer);
		break;
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConGyroscope(const int ControllerIndex, bool& Success, FVector& Gyroscope) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	Gyroscope = FVector::ZeroVector;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().GetJoyConGyroscope(ControllerIndex, Gyroscope);
		break;
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConVector(const int ControllerIndex, bool& Success, FRotator& Vector) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	Vector = FRotator::ZeroRotator;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().GetJoyConVector(ControllerIndex, Vector);
		break;
	}
}

void UJoyConDriverFunctionLibrary::ReCenterJoyCon(const int ControllerIndex, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().ReCenterJoyCon(ControllerIndex);
		break;
	}
}

void UJoyConDriverFunctionLibrary::SetJoyConFilterCoefficient(const int ControllerIndex, const float Coefficient, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().SetJoyConFilterCoefficient(ControllerIndex, Coefficient);
		break;
	}
}

void UJoyConDriverFunctionLibrary::SetJoyConGripMode(const int GripIndex, const EGripMode GripMode, bool& Success) {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	Success = false;
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi == nullptr) continue;
		Success = JoyConInputApi->Get().SetJoyConGripMode(GripIndex, static_cast<uint8>(GripMode));
		break;
	}
}
