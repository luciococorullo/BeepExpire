/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SparkCaptureFeedback)
SDC_EXPORTED_SYMBOL
@interface SDCSparkCaptureFeedback : NSObject

@property (class, nonatomic, readonly) SDCSparkCaptureFeedback *defaultFeedback;

@property (nonatomic, strong, nonnull) SDCFeedback *success;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (nullable instancetype)sparkCaptureFeedbackFromJSONString:(nonnull NSString *)JSONString
                                                      error:(NSError *_Nullable *_Nullable)error;
@end

NS_ASSUME_NONNULL_END
