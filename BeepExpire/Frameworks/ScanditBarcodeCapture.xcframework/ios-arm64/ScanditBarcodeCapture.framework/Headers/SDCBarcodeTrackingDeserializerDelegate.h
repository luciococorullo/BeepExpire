/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeTrackingDeserializer;
@class SDCBarcodeTracking;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeTrackingDeserializerDelegate)
@protocol SDCBarcodeTrackingDeserializerDelegate <NSObject>

- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
          didStartDeserializingMode:(SDCBarcodeTracking *)mode
                      fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
         didFinishDeserializingMode:(SDCBarcodeTracking *)mode
                      fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
      didStartDeserializingSettings:(SDCBarcodeTrackingSettings *)settings
                      fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
     didFinishDeserializingSettings:(SDCBarcodeTrackingSettings *)settings
                      fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didStartDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                        fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didFinishDeserializingBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                         fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didStartDeserializingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay *)overlay
                           fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeTrackingDeserializer:(SDCBarcodeTrackingDeserializer *)deserializer
    didFinishDeserializingAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay *)overlay
                            fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
