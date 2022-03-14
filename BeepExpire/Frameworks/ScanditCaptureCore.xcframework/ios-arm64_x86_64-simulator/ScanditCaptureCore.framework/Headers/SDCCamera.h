/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCFrameSource.h>

@class SDCCameraSettings;

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCCameraPosition) {
    SDCCameraPositionWorldFacing,
    SDCCameraPositionUserFacing,
    SDCCameraPositionUnspecified
} NS_SWIFT_NAME(CameraPosition);

SDC_EXTERN NSString *_Nonnull NSStringFromCameraPosition(SDCCameraPosition cameraPosition) NS_SWIFT_NAME(getter:SDCCameraPosition.jsonString(self:));
SDC_EXTERN BOOL SDCCameraPositionFromJSONString(NSString *_Nonnull JSONString, SDCCameraPosition *_Nonnull cameraPosition);

typedef NS_CLOSED_ENUM(NSUInteger, SDCTorchState) {
    SDCTorchStateOff = 0,
    SDCTorchStateOn = 1,
    SDCTorchStateAuto = 2
} NS_SWIFT_NAME(TorchState);

SDC_EXTERN NSString *_Nonnull NSStringFromTorchState(SDCTorchState torchState) NS_SWIFT_NAME(getter:SDCTorchState.jsonString(self:));
SDC_EXTERN BOOL SDCTorchStateFromJSONString(NSString *_Nonnull JSONString, SDCTorchState *_Nonnull torchState);
// clang-format on

NS_SWIFT_NAME(TorchListener)
@protocol SDCTorchListener <NSObject>
- (void)didChangeTorchToState:(SDCTorchState)torchState;
@end

NS_SWIFT_NAME(Camera)
SDC_EXPORTED_SYMBOL
@interface SDCCamera : NSObject <SDCFrameSource>

@property (class, nonatomic, nullable, readonly) SDCCamera *defaultCamera;
@property (class, nonatomic, nullable, readonly) SDCCamera *sparkCaptureCamera;
@property (nonatomic, readonly) BOOL isTorchAvailable;
@property (nonatomic, readonly) SDCCameraPosition position;
@property (nonatomic, assign) SDCTorchState desiredTorchState;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (nullable SDCCamera *)cameraAtPosition:(SDCCameraPosition)position NS_SWIFT_NAME(init(position:));

+ (nullable instancetype)cameraFromJSONString:(nonnull NSString *)JSONString
                                        error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:));

- (void)applySettings:(nonnull SDCCameraSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

- (void)addTorchListener:(nonnull id<SDCTorchListener>)listener NS_SWIFT_NAME(addTorchListener(_:));
- (void)removeTorchListener:(nonnull id<SDCTorchListener>)listener
    NS_SWIFT_NAME(removeTorchListener(_:));

- (void)switchToDesiredState:(SDCFrameSourceState)state;
- (void)switchToDesiredState:(SDCFrameSourceState)state
           completionHandler:(nullable void (^)(BOOL))completionHandler;

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
