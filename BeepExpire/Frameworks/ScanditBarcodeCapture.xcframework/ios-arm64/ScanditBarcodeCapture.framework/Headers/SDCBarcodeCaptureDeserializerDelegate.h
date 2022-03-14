/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeCaptureDeserializer;
@class SDCBarcodeCapture;
@class SDCBarcodeCaptureSettings;
@class SDCBarcodeCaptureOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureDeserializerDelegate)
@protocol SDCBarcodeCaptureDeserializerDelegate <NSObject>

- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
         didStartDeserializingMode:(SDCBarcodeCapture *)mode
                     fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
        didFinishDeserializingMode:(SDCBarcodeCapture *)mode
                     fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
     didStartDeserializingSettings:(SDCBarcodeCaptureSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
    didFinishDeserializingSettings:(SDCBarcodeCaptureSettings *)settings
                     fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
      didStartDeserializingOverlay:(SDCBarcodeCaptureOverlay *)overlay
                     fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeCaptureDeserializer:(SDCBarcodeCaptureDeserializer *)deserializer
     didFinishDeserializingOverlay:(SDCBarcodeCaptureOverlay *)overlay
                     fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
