/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#include <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@protocol SDCFrameData;

NS_SWIFT_NAME(DataCaptureMode)
@protocol SDCDataCaptureMode <NSObject>

@property (nonatomic, assign, getter=isEnabled) BOOL enabled NS_SWIFT_NAME(isEnabled);

@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;

@end

NS_ASSUME_NONNULL_END
