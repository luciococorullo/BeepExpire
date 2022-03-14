/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCDataCaptureContextDeserializer;
@class SDCJSONValue;

NS_SWIFT_NAME(DataCaptureContextDeserializerDelegate)
@protocol SDCDataCaptureContextDeserializerDelegate <NSObject>

- (void)contextDeserializer:(SDCDataCaptureContextDeserializer *)deserializer
    didStartDeserializingContext:(SDCDataCaptureContext *)context
                   fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)contextDeserializer:(SDCDataCaptureContextDeserializer *)deserializer
    didFinishDeserializingContext:(SDCDataCaptureContext *)context
                    fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
