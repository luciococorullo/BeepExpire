/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>

@class SDCBarcodeSelection;
@class SDCDataCaptureContext;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionBasicOverlay;
@protocol SDCBarcodeSelectionDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionDeserializer)
@interface SDCBarcodeSelectionDeserializer : NSObject <SDCDataCaptureModeDeserializer>

@property (nonatomic, weak, nullable) id<SDCBarcodeSelectionDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)barcodeSelectionDeserializer;

- (nullable SDCBarcodeSelection *)modeFromJSONString:(NSString *)JSONString
                                         withContext:(SDCDataCaptureContext *)context
                                               error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeSelection *)updateMode:(SDCBarcodeSelection *)barcodeSelection
                              fromJSONString:(NSString *)JSONString
                                       error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeSelectionSettings *)settingsFromJSONString:(NSString *)JSONString
                                                           error:
                                                               (NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeSelectionSettings *)updateSettings:(SDCBarcodeSelectionSettings *)settings
                                          fromJSONString:(NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;

// clang-format off
- (nullable SDCBarcodeSelectionBasicOverlay *)basicOverlayFromJSONString:(NSString *)JSONString
                                                                withMode:(SDCBarcodeSelection *)mode
                                                                   error:(NSError *_Nullable *_Nullable)error;
// clang-format on

// clang-format off
- (nullable SDCBarcodeSelectionBasicOverlay *)updateBasicOverlay:(SDCBarcodeSelectionBasicOverlay *)overlay
                                                  fromJSONString:(NSString *)JSONString
                                                           error:(NSError *_Nullable *_Nullable)error;
// clang-format on

@end

NS_ASSUME_NONNULL_END
