/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcodeTracking;
@class SDCDataCaptureContext;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCBarcodeTrackingAdvancedOverlay;
@protocol SDCBarcodeTrackingDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeTrackingDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingDeserializer : NSObject <SDCDataCaptureModeDeserializer>

@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)barcodeTrackingDeserializer;

- (nullable SDCBarcodeTracking *)modeFromJSONString:(NSString *)JSONString
                                        withContext:(SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeTracking *)updateMode:(SDCBarcodeTracking *)barcodeTracking
                             fromJSONString:(NSString *)JSONString
                                      error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeTrackingSettings *)settingsFromJSONString:(NSString *)JSONString
                                                          error:
                                                              (NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeTrackingSettings *)updateSettings:(SDCBarcodeTrackingSettings *)settings
                                         fromJSONString:(NSString *)JSONString
                                                  error:(NSError *_Nullable *_Nullable)error;

// clang-format off
- (nullable SDCBarcodeTrackingBasicOverlay *)basicOverlayFromJSONString:(NSString *)JSONString
                                                               withMode:(SDCBarcodeTracking *)mode
                                                                  error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeTrackingBasicOverlay *)updateBasicOverlay:(SDCBarcodeTrackingBasicOverlay *)overlay
                                                 fromJSONString:(NSString *)JSONString
                                                          error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeTrackingAdvancedOverlay *)advancedOverlayFromJSONString:(NSString *)JSONString
                                                               withMode:(SDCBarcodeTracking *)mode
                                                                  error:(NSError *_Nullable *_Nullable)error  API_AVAILABLE(ios(10.0));
- (nullable SDCBarcodeTrackingAdvancedOverlay *)updateAdvancedOverlay:(SDCBarcodeTrackingAdvancedOverlay *)overlay
                                                 fromJSONString:(NSString *)JSONString
                                                          error:(NSError *_Nullable *_Nullable)error  API_AVAILABLE(ios(10.0));
// clang-format on

@end

NS_ASSUME_NONNULL_END
