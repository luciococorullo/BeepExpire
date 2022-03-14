/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@protocol SDCViewfinder;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ViewfinderDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCViewfinderDeserializer : NSObject
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (nonnull instancetype)viewfinderDeserializer;

- (nullable id<SDCViewfinder>)viewfinderFromJSONString:(nonnull NSString *)JSONString
                                                 error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
