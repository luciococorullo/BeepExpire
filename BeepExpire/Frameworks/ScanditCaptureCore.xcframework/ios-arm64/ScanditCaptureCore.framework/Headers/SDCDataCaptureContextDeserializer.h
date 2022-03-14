/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDCDataCaptureContextDeserializerDelegate;
@protocol SDCDataCaptureModeDeserializer;
@protocol SDCDataCaptureComponentDeserializer;
@protocol SDCDataCaptureComponent;

@class SDCDataCaptureContext;
@class SDCDataCaptureView;
@class SDCFrameSourceDeserializer;
@class SDCDataCaptureViewDeserializer;
@class SDCDataCaptureContextDeserializerResult;

NS_SWIFT_NAME(DataCaptureContextDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureContextDeserializer : NSObject

@property (nonatomic, weak, nullable) id<SDCDataCaptureContextDeserializerDelegate> delegate;
@property (nonatomic, assign) BOOL avoidThreadDependencies;

// clang-format off
+ (instancetype)contextDeserializerWithFrameSourceDeserializer:(SDCFrameSourceDeserializer *)frameSourceDeserializer
                                              viewDeserializer:(SDCDataCaptureViewDeserializer *)viewDeserializer
                                             modeDeserializers:(NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers
                                         componentDeserializer:(NSArray<id<SDCDataCaptureComponentDeserializer>> *)componentDeserializers
    NS_SWIFT_NAME(init(frameSourceDeserializer:viewDeserializer:modeDeserializers:componentDeserializers:));

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (nullable SDCDataCaptureContextDeserializerResult *)contextFromJSONString:(NSString *)jsonString
                                                                      error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCDataCaptureContextDeserializerResult *)updateContext:(SDCDataCaptureContext *)context
                                                               view:(nullable SDCDataCaptureView *)view
                                                            components:(NSArray<id<SDCDataCaptureComponent>> *)components
                                                           fromJSON:(NSString *)jsonString
                                                              error:(NSError *_Nullable *_Nullable)error;
// clang-format on
@end

NS_ASSUME_NONNULL_END
