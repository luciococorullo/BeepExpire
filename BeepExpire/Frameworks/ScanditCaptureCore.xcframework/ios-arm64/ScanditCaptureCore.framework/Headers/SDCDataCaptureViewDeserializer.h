/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureView.h>

@class SDCDataCaptureViewDeserializerHelper;
@protocol SDCDataCaptureViewDeserializerDelegate;
@protocol SDCDataCaptureModeDeserializer;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DataCaptureViewDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureViewDeserializer : NSObject

@property (nonatomic, weak, nullable) id<SDCDataCaptureViewDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)dataCaptureViewDeserializerWithModeDeserializers:
    (NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers
    NS_SWIFT_NAME(init(modeDeserializers:));

- (nullable SDCDataCaptureView *)viewFromJSONString:(NSString *)JSONString
                                        withContext:(SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCDataCaptureView *)updateView:(SDCDataCaptureView *)view
                             fromJSONString:(NSString *)JSONString
                                      error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
