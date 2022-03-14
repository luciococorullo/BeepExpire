/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(RectangularViewfinderAnimation)
SDC_EXPORTED_SYMBOL
@interface SDCRectangularViewfinderAnimation : NSObject

@property (nonatomic, readonly) BOOL isLooping;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

- (nonnull instancetype)initWithLooping:(BOOL)looping;

@end

NS_ASSUME_NONNULL_END
