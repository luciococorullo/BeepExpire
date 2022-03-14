/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCSparkCaptureDeserializer;
@class SDCSparkCapture;
@class SDCSparkCaptureSettings;
@class SDCSparkCaptureOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SparkCaptureDeserializerDelegate)
@protocol SDCSparkCaptureDeserializerDelegate <NSObject>

- (void)sparkCaptureDeserializer:(SDCSparkCaptureDeserializer *)deserializer
       didStartDeserializingMode:(SDCSparkCapture *)mode
                   fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)sparkCaptureDeserializer:(SDCSparkCaptureDeserializer *)deserializer
      didFinishDeserializingMode:(SDCSparkCapture *)mode
                   fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)sparkCaptureDeserializer:(SDCSparkCaptureDeserializer *)deserializer
    didStartDeserializingSettings:(SDCSparkCaptureSettings *)settings
                    fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)sparkCaptureDeserializer:(SDCSparkCaptureDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCSparkCaptureSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
