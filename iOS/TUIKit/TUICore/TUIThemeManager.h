//
//  TUIThemeManager.h
//  TUICore
//
//  Created by harvy on 2022/1/5.
//  Copyright © 2023 Tencent. All rights reserved.
//
/**
 *
 * Storage structure of theme for each module
 *      | The root path of the theme resource（ThemeResourcePath）
 *      |
 *      |------ Theme one（named with theme identifier）
 *      |                 |
 *      |                 |------- manifest.plist (configuration information for the theme)
 *      |                 |------- resource
 *      |-------Theme two
 *      |                 |
 *      |                 |------ manifest.plist (configuration information for the theme)
 *      |                 |------ resource
 */

#import <Foundation/Foundation.h>
#import "TUIDefine.h"

@class TUITheme;
@class TUIThemeManager;

NS_ASSUME_NONNULL_BEGIN

#define TUIShareThemeManager TUIThemeManager.shareManager

/**
 * Notifications when the app's theme has changed
 */
#define TUIDidApplyingThemeChangedNotfication @"TUIDidApplyingThemeChangedNotfication"
#define TUIDidApplyingThemeChangedNotficationThemeKey @"TUIDidApplyingThemeChangedNotficationThemeKey"
#define TUIDidApplyingThemeChangedNotficationModuleKey @"TUIDidApplyingThemeChangedNotficationModuleKey"

/**
 * Register the theme resource root path of the module
 */
#define TUIRegisterThemeResourcePath(path, module) [TUIShareThemeManager registerThemeResourcePath:path forModule:module];

/**
 * Get the theme used by the module
 */
#define TUICurrentTheme(module) [TUIShareThemeManager currentThemeForModule:module]

/**
 * Get the dark night theme of the module
 */
#define TUIDarkTheme(module) [TUIShareThemeManager darkThemeForModule:module]

/**
 * Get dynamic colors that change with theme
 */
#define TUIDynamicColor(colorKey, themeModule, defaultHex) [TUITheme dynamicColor:colorKey module:themeModule defaultColor:defaultHex]
#define TUIDemoDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleDemo, defaultHex)
#define TUICoreDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleCore, defaultHex)
#define TUIChatDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleChat, defaultHex)
#define TUIConversationDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleConversation, defaultHex)
#define TUIConversationGroupDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleConversationGroup, defaultHex)
#define TUIContactDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleContact, defaultHex)
#define TUISearchDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleSearch, defaultHex)
#define TUICallKitDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleCalling, defaultHex)
#define TUIPollDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModulePoll, defaultHex)
#define TUIGroupNoteDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleGroupNote, defaultHex)
#define TIMCommonDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleTIMCommon, defaultHex)
#define TUITranslationDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleTranslation, defaultHex)
#define TUIVoiceToTextDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleVoiceToText, defaultHex)
#define TUICustomerServicePluginDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleCustomerService, defaultHex)
#define TUIMultimediaPluginDynamicColor(colorKey, defaultHex) TUIDynamicColor(colorKey, TUIThemeModuleMultimedia, defaultHex)

/**
 * Get dynamic image that change with theme
 */
#define TUIDemoBundleThemeImage(imageKey, defaultImageName) TUIDemoDynamicImage(imageKey, TUIDemoCommonBundleImage(defaultImageName))
#define TUICoreBundleThemeImage(imageKey, defaultImageName) TUICoreDynamicImage(imageKey, TUICoreCommonBundleImage(defaultImageName))
#define TUIChatBundleThemeImage(imageKey, defaultImageName) TUIChatDynamicImage(imageKey, TUIChatCommonBundleImage(defaultImageName))
#define TUIConversationBundleThemeImage(imageKey, defaultImageName) TUIConversationDynamicImage(imageKey, TUIConversationCommonBundleImage(defaultImageName))
#define TUIContactBundleThemeImage(imageKey, defaultImageName) TUIContactDynamicImage(imageKey, TUIContactCommonBundleImage(defaultImageName))
#define TUISearchBundleThemeImage(imageKey, defaultImageName) TUISearchDynamicImage(imageKey, TUISearchCommonBundleImage(defaultImageName))
#define TUICallingBundleThemeImage(imageKey, defaultImageName) TUICallingDynamicImage(imageKey, TUICallingCommonBundleImage(defaultImageName))
#define TUIPollBundleThemeImage(imageKey, defaultImageName) TUIPollDynamicImage(imageKey, TUIPollCommonBundleImage(defaultImageName))
#define TUIGroupNoteBundleThemeImage(imageKey, defaultImageName) TUIGroupNoteDynamicImage(imageKey, TUIGroupNoteCommonBundleImage(defaultImageName))
#define TIMCommonBundleThemeImage(imageKey, defaultImageName) TIMCommonDynamicImage(imageKey, TIMCommonBundleImage(defaultImageName))
#define TUITranslationBundleThemeImage(imageKey, defaultImageName) TUITranslationDynamicImage(imageKey, TUITranslationCommonBundleImage(defaultImageName))
#define TUIVoiceToTextBundleThemeImage(imageKey, defaultImageName) TUIVoiceToTextDynamicImage(imageKey, TUIVoiceToTextCommonBundleImage(defaultImageName))
#define TUICustomerServicePluginBundleThemeImage(imageKey,defaultImageName) \
    TUICustomerServicePluginDynamicImage(imageKey,TUICustomerServicePluginCommonBundleImage(defaultImageName))
#define TUIMultimediaPluginBundleThemeImage(imageKey, defaultImageName) \
    TUIMultimediaPluginDynamicImage(imageKey, TUIMultimediaPluginCommonBundleImage(defaultImageName))

#define TUIDynamicImage(imageKey, themeModule, defaultImg) [TUITheme dynamicImage:imageKey module:themeModule defaultImage:defaultImg]
#define TUIDemoDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleDemo, defaultImg)
#define TUICoreDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleCore, defaultImg)
#define TUIChatDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleChat, defaultImg)
#define TUIConversationDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleConversation, defaultImg)
#define TUIConversationGroupDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleConversationGroup, defaultImg)
#define TUIContactDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleContact, defaultImg)
#define TUISearchDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleSearch, defaultImg)
#define TUICallingDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleCalling, defaultImg)
#define TUIPollDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModulePoll, defaultImg)
#define TUIGroupNoteDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleGroupNote, defaultImg)
#define TIMCommonDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleTIMCommon, defaultImg)
#define TUITranslationDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleTranslation, defaultImg)
#define TUIVoiceToTextDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleVoiceToText, defaultImg)
#define TUICustomerServicePluginDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleCustomerService, defaultImg)
#define TUIMultimediaPluginDynamicImage(imageKey, defaultImg) TUIDynamicImage(imageKey, TUIThemeModuleMultimedia, defaultImg)

#define __TUIDefaultBundleImage(imageBundlePath) [UIImage imageWithContentsOfFile:imageBundlePath]
#define TUIDemoCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIDemoImagePath(imageName))
#define TUICoreCommonBundleImage(imageName) __TUIDefaultBundleImage(TUICoreImagePath(imageName))
#define TUIChatCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIChatImagePath(imageName))
#define TUIConversationCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIConversationImagePath(imageName))
#define TUIContactCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIContactImagePath(imageName))
#define TUISearchCommonBundleImage(imageName) __TUIDefaultBundleImage(TUISearchImagePath(imageName))
#define TUICallingCommonBundleImage(imageName) __TUIDefaultBundleImage(TUICallingImagePath(imageName))
#define TUIPollCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIPollImagePath(imageName))
#define TUIGroupNoteCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIGroupNoteImagePath(imageName))
#define TIMCommonBundleImage(imageName) __TUIDefaultBundleImage(TIMCommonImagePath(imageName))
#define TUITranslationCommonBundleImage(imageName) __TUIDefaultBundleImage(TUITranslationImagePath(imageName))
#define TUIVoiceToTextCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIVoiceToTextImagePath(imageName))
#define TUICustomerServicePluginCommonBundleImage(imageName) __TUIDefaultBundleImage(TUICustomerServicePluginImagePath(imageName))
#define TUIMultimediaPluginCommonBundleImage(imageName) __TUIDefaultBundleImage(TUIMultimediaPluginImagePath(imageName))

/**
 * The module of the theme
 */
typedef NS_ENUM(NSInteger, TUIThemeModule) {
    TUIThemeModuleAll = 0xFFFFFF,
    TUIThemeModuleDemo = 0x1 << 0,
    TUIThemeModuleCore = 0x1 << 1,
    TUIThemeModuleChat = 0x1 << 2,
    TUIThemeModuleConversation = 0x1 << 3,
    TUIThemeModuleContact = 0x1 << 4,
    TUIThemeModuleGroup = 0x1 << 5, // The TUIGroup component has been removed in version 8.4
    TUIThemeModuleSearch = 0x1 << 6,
    TUIThemeModuleCalling = 0x1 << 7,

    TUIThemeModuleDemo_Minimalist = 0x1 << 8,
    TUIThemeModuleCore_Minimalist = 0x1 << 9,
    TUIThemeModuleChat_Minimalist = 0x1 << 10,
    TUIThemeModuleConversation_Minimalist = 0x1 << 11,
    TUIThemeModuleContact_Minimalist = 0x1 << 12,
    TUIThemeModuleGroup_Minimalist = 0x1 << 13, // The TUIGroup component has been removed in version 8.4
    TUIThemeModuleSearch_Minimalist = 0x1 << 14,
    TUIThemeModuleCalling_Minimalist = 0x1 << 15,

    // UI Plugins
    TUIThemeModulePoll = 0x1 << 16,
    TUIThemeModuleGroupNote = 0x1 << 17,
    TUIThemeModuleTIMCommon = 0x1 << 18,
    TUIThemeModuleTranslation = 0x1 << 19,
    TUIThemeModuleConversationGroup = 0x1 << 20,
    TUIThemeModuleVoiceToText = 0x1 << 21,
    TUIThemeModuleCustomerService = 0x1 << 22,
    TUIThemeModuleChatBot = 0x1 << 23,
    
    TUIThemeModuleRoomKit = 0x1 << 24,

    TUIThemeModuleMultimedia = 0x1 << 25,
};

@interface TUITheme : NSObject

@property(nonatomic, copy) NSString *themeID;
@property(nonatomic, assign) TUIThemeModule module;
@property(nonatomic, copy, nullable) NSString *themeDesc;
@property(nonatomic, strong) NSDictionary *manifest;
@property(nonatomic, copy) NSString *resourcePath;

+ (UIColor *__nullable)dynamicColor:(NSString *)colorKey module:(TUIThemeModule)module defaultColor:(NSString *)hex;
+ (UIImage *__nullable)dynamicImage:(NSString *)imageKey module:(TUIThemeModule)module defaultImage:(UIImage *)image;

@end

@protocol TUIThemeManagerListener <NSObject>

/**
 * Callback for theme changes, you can also listen to the notification named TUIDidApplyingThemeChangedNotfication
 */
- (void)onApplyTheme:(TUITheme *)theme module:(TUIThemeModule)module;

- (void)onError:(NSInteger)code message:(NSString *)message userInfo:(NSString *)userInfo;

@end

@interface TUIThemeManager : NSObject

+ (instancetype)shareManager;

- (void)addListener:(id<TUIThemeManagerListener>)listener;
- (void)removeListener:(id<TUIThemeManagerListener>)listener;

/**
 * Register the theme resource root path of the module
 * If the ID of the dark theme is not specified, @"dark" is used internally by default to indicate the dark mode
 */
- (void)registerThemeResourcePath:(NSString *)path forModule:(TUIThemeModule)module;
- (void)registerThemeResourcePath:(NSString *)path darkThemeID:(NSString *)darkThemeID forModule:(TUIThemeModule)module;

- (TUITheme *)currentThemeForModule:(TUIThemeModule)module;
- (TUITheme *)darkThemeForModule:(TUIThemeModule)module;

- (void)applyTheme:(NSString *)themeID forModule:(TUIThemeModule)module;
- (void)unApplyThemeForModule:(TUIThemeModule)module;

@end

NS_ASSUME_NONNULL_END
