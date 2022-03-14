/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureFeedback)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureFeedback : NSObject

@property (class, nonatomic, readonly) SDCBarcodeCaptureFeedback *defaultFeedback;

@property (nonatomic, strong, nonnull) SDCFeedback *success;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (nullable instancetype)barcodeCaptureFeedbackFromJSONString:(nonnull NSString *)JSONString
                                                        error:(NSError *_Nullable *_Nullable)error;
@end

NS_ASSUME_NONNULL_END
