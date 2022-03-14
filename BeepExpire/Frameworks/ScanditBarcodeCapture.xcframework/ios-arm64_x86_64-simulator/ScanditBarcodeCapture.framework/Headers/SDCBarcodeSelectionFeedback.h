/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCFeedback;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionFeedback)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionFeedback : NSObject

@property (class, nonatomic, readonly) SDCBarcodeSelectionFeedback *defaultFeedback;

@property (nonatomic, strong, nonnull) SDCFeedback *selection;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (nullable instancetype)barcodeSelectionFeedbackFromJSONString:(nonnull NSString *)JSONString
                                                          error:
                                                              (NSError *_Nullable *_Nullable)error;
@end

NS_ASSUME_NONNULL_END
