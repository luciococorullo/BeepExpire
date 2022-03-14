/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

SDC_EXTERN NSString *_Nonnull const SDCBarcodeTrackingSettingsErrorDomain
    NS_SWIFT_NAME(BarcodeTrackingSettingsErrorDomain);

@class SDCSymbologySettings;

typedef NS_ENUM(NSUInteger, SDCBarcodeTrackingScenario) {
    SDCBarcodeTrackingScenarioA NS_SWIFT_NAME(a),
    SDCBarcodeTrackingScenarioB NS_SWIFT_NAME(b),
} NS_SWIFT_NAME(BarcodeTrackingScenario);

NS_SWIFT_NAME(BarcodeTrackingSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingSettings : NSObject <NSCopying>

@property (nonatomic, nonnull, readonly)
    NSSet<NSNumber *> *enabledSymbologies NS_SWIFT_NAME(enabledSymbologyValues);

+ (instancetype)settings;
+ (instancetype)settingsWithScenario:(SDCBarcodeTrackingScenario)scenario;

- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;

- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));

- (nullable id)valueForProperty:(NSString *)property;

- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies;

- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

@end

NS_ASSUME_NONNULL_END
