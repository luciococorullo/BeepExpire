/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCFrameSourceDeserializer;
@class SDCCameraSettings;
@class SDCJSONValue;
@protocol SDCFrameSource;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FrameSourceDeserializerDelegate)
@protocol SDCFrameSourceDeserializerDelegate <NSObject>

- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didStartDeserializingFrameSource:(id<SDCFrameSource>)frameSource
                       fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didFinishDeserializingFrameSource:(id<SDCFrameSource>)frameSource
                        fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didStartDeserializingCameraSettings:(SDCCameraSettings *)settings
                          fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)frameSourceDeserializer:(SDCFrameSourceDeserializer *)deserializer
    didFinishDeserializingCameraSettings:(SDCCameraSettings *)settings
                           fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
