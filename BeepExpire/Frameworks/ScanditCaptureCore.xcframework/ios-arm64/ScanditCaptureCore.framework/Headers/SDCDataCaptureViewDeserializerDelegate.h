/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureView;
@class SDCDataCaptureViewDeserializer;
@class SDCJSONValue;

NS_SWIFT_NAME(DataCaptureViewDeserializerDelegate)
@protocol SDCDataCaptureViewDeserializerDelegate <NSObject>

- (void)viewDeserializer:(SDCDataCaptureViewDeserializer *)deserializer
    didStartDeserializingView:(SDCDataCaptureView *)view
                fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)viewDeserializer:(SDCDataCaptureViewDeserializer *)deserializer
    didFinishDeserializingView:(SDCDataCaptureView *)view
                 fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
