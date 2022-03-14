/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class SDCBarcodeSelectionDeserializer;
@class SDCBarcodeSelection;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionBasicOverlay;
@class SDCJSONValue;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionDeserializerDelegate)
@protocol SDCBarcodeSelectionDeserializerDelegate <NSObject>

- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
           didStartDeserializingMode:(SDCBarcodeSelection *)mode
                       fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
          didFinishDeserializingMode:(SDCBarcodeSelection *)mode
                       fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
       didStartDeserializingSettings:(SDCBarcodeSelectionSettings *)settings
                       fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
      didFinishDeserializingSettings:(SDCBarcodeSelectionSettings *)settings
                       fromJSONValue:(SDCJSONValue *)JSONValue;

- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
    didStartDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay *)overlay
                        fromJSONValue:(SDCJSONValue *)JSONValue;
- (void)barcodeSelectionDeserializer:(SDCBarcodeSelectionDeserializer *)deserializer
    didFinishDeserializingBasicOverlay:(SDCBarcodeSelectionBasicOverlay *)overlay
                         fromJSONValue:(SDCJSONValue *)JSONValue;

@end

NS_ASSUME_NONNULL_END
