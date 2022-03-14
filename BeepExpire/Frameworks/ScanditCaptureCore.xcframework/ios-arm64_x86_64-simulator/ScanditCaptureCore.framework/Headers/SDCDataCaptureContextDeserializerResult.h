/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCDataCaptureView;
@protocol SDCDataCaptureComponent;

NS_SWIFT_NAME(DataCaptureContextDeserializerResult)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureContextDeserializerResult : NSObject

@property (nonatomic, strong, nonnull, readonly) SDCDataCaptureContext *context;
@property (nonatomic, strong, nullable, readonly) SDCDataCaptureView *view;
@property (nonatomic, strong, nonnull, readonly) NSArray<NSString *> *warnings;
@property (nonatomic, strong, nonnull, readonly) NSArray<id<SDCDataCaptureComponent>> *components;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
