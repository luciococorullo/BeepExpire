/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

#import <ScanditCaptureCore/SDCBase.h>

@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCFrameSourceState) {
    SDCFrameSourceStateOff,
    SDCFrameSourceStateOn,
    SDCFrameSourceStateStarting,
    SDCFrameSourceStateStopping,
    SDCFrameSourceStateStandby,
    SDCFrameSourceStateBootingUp,
    SDCFrameSourceStateWakingUp,
    SDCFrameSourceStateGoingToSleep,
    SDCFrameSourceStateShuttingDown
} NS_SWIFT_NAME(FrameSourceState);

SDC_EXTERN NSString *_Nonnull NSStringFromFrameSourceState(SDCFrameSourceState state) NS_SWIFT_NAME(getter:SDCFrameSourceState.jsonString(self:));
SDC_EXTERN BOOL SDCFrameSourceStateFromJSONString(NSString *_Nonnull JSONString, SDCFrameSourceState *_Nonnull frameSourceState);
// clang-format on

@protocol SDCFrameSource;

NS_SWIFT_NAME(FrameSourceListener)
@protocol SDCFrameSourceListener <NSObject>

@required

- (void)frameSource:(id<SDCFrameSource>)source didChangeState:(SDCFrameSourceState)newState;

- (void)frameSource:(id<SDCFrameSource>)source didOutputFrame:(id<SDCFrameData>)frame;

@optional

- (void)didStartObservingFrameSource:(id<SDCFrameSource>)source;

- (void)didStopObservingFrameSource:(id<SDCFrameSource>)source;

@end

NS_SWIFT_NAME(FrameSource)
@protocol SDCFrameSource <NSObject>

- (void)switchToDesiredState:(SDCFrameSourceState)state
           completionHandler:(nullable void (^)(BOOL))completionHandler;

@property (nonatomic, readonly) SDCFrameSourceState desiredState;
@property (nonatomic, readonly) SDCFrameSourceState currentState;

- (void)addListener:(nonnull id<SDCFrameSourceListener>)listener NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCFrameSourceListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

@end

NS_ASSUME_NONNULL_END
