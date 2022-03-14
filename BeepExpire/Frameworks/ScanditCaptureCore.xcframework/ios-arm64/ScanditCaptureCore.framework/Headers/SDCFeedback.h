/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCVibration;
@class SDCSound;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Feedback)
SDC_EXPORTED_SYMBOL
@interface SDCFeedback : NSObject

@property (class, nonatomic, readonly) SDCFeedback *defaultFeedback;

- (instancetype)initWithVibration:(nullable SDCVibration *)vibration
                            sound:(nullable SDCSound *)sound;

+ (nullable instancetype)feedbackFromJSONString:(nonnull NSString *)JSONString
                                          error:(NSError *_Nullable *_Nullable)error;

@property (nonatomic, nullable, readonly) SDCVibration *vibration;
@property (nonatomic, nullable, readonly) SDCSound *sound;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

- (void)emit;

@end

NS_ASSUME_NONNULL_END
