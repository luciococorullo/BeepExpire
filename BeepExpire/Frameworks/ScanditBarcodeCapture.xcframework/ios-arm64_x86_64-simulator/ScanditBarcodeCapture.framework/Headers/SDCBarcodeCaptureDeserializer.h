/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>

@class SDCBarcodeCapture;
@class SDCDataCaptureContext;
@class SDCBarcodeCaptureSettings;
@class SDCBarcodeCaptureOverlay;
@protocol SDCBarcodeCaptureDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureDeserializer)
@interface SDCBarcodeCaptureDeserializer : NSObject <SDCDataCaptureModeDeserializer>

@property (nonatomic, weak, nullable) id<SDCBarcodeCaptureDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)barcodeCaptureDeserializer;

- (nullable SDCBarcodeCapture *)modeFromJSONString:(NSString *)JSONString
                                       withContext:(SDCDataCaptureContext *)context
                                             error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeCapture *)updateMode:(SDCBarcodeCapture *)barcodeCapture
                            fromJSONString:(NSString *)JSONString
                                     error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeCaptureSettings *)settingsFromJSONString:(NSString *)JSONString
                                                         error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeCaptureSettings *)updateSettings:(SDCBarcodeCaptureSettings *)settings
                                        fromJSONString:(NSString *)JSONString
                                                 error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCBarcodeCaptureOverlay *)overlayFromJSONString:(NSString *)JSONString
                                                    withMode:(SDCBarcodeCapture *)mode
                                                       error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCBarcodeCaptureOverlay *)updateOverlay:(SDCBarcodeCaptureOverlay *)overlay
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
