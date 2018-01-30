#ifndef _MACROHTML_H
#define _MACROHTML_H
// ============================================================================
// Meta Macros (Macros used for information about macros)
// ============================================================================
// Return the first of two arguments
#define META_GET(_0, _1) _0
//
// Return the second of two arguments
#define META_GET_(_0, _1) _1
//
// Concatenate two arguments
#define META_JOIN(_0, _1) _0 ## _1
//
// Expand macros and concatenate
#define META_EJOIN(_0, _1) META_JOIN(_0, _1)
//
// Truncate everything after first comma
#define META_FIRST(_, ...) _
//
// Expand argument and pass to FIRST
#define META_EFIRST(_) META_FIRST(_)
//
// Remove everything before first comma
#define META_REST(_0, ...) __VA_ARGS__
//
// Branch between GET and GET_
#define META_GET_GET(...)\
    META_EJOIN(META_GET, META_EFIRST(META_REST(,,##__VA_ARGS__ _)))
//
// If arguements are present
#define META_IFARGS(YES, NO, ...)\
    META_GET_GET(__VA_ARGS__)(YES, NO)
// ============================================================================
// HTML Helpers
// ============================================================================
// CLOSE_SCOPE
//   Used for HTML tags that use self closure
//   (e.g.) <body>Foo Bar</body>
#define CLOSE_SCOPE(tag, content, ...)\
    META_IFARGS(\
        <tag __VA_ARGS__>content</tag>,\
        <tag>content</tag>,\
        __VA_ARGS__\
    )
//    
// CLOSE_SELF
//   Used for HTML tags that use self closure
//   (e.g.) <a href="./home" />
#define CLOSE_SELF(tag, ...)\
    META_IFARGS(\
        <tag __VA_ARGS__ />,\
        <tag/>,\
        __VA_ARGS__\
    )
//
// CLOSE_NONE
//   Used for HTML tags that have no closure or content
//   (e.g.) <link>
#define CLOSE_NONE(tag, ...)\
    META_IFARGS(\
        <tag __VA_ARGS__>,\
        <tag>,\
        __VA_ARGS__\
    )
//
// CLOSE_COMMENT
//   Used for HTML tags that have no closure or content
//   (e.g.) <link>
#define CLOSE_COMMENT(...)\
    META_IFARGS(\
        <!-- __VA_ARGS__ -->,\
        <!-- I am a teapot -->,\
        __VA_ARGS__\
    )
//
// TAG_OPEN
//    Generic Tag Opening
#define TAG_OPEN(tag, ...)\
    META_IFARGS(\
        <tag __VA_ARGS__>,\
        <tag>,\
        __VA_ARGS__\
    )
//
// TAG_OPEN
//    Generic Tag Opening
#define TAG_CLOSE(tag, ...)\
    META_IFARGS(\
        </tag __VA_ARGS__>,\
        </tag>,\
        __VA_ARGS__\
    )
//
// Pass in a value and stringify 
#define ATTRIBUTE_STR(name,value)\
    name=#value
// Pass in a string literal 
#define ATTRIBUTE(name,value)\
    name=value
// Pass in a string literal 
#define TEXT(...)\
    __VA_ARGS__
// ============================================================================
// HTML - Generic
// ============================================================================
#define DOCTYPE(content)\
    CLOSE_NONE(\
        !DOCTYPE\
        content\
    )
#define COMMENT(...)\
    CLOSE_COMMENT(\
        __VA_ARGS__\
    )
#define HTML(content, ...)\
    CLOSE_SCOPE(\
        html,\
        content,\
        __VA_ARGS__\
    )
#define HEAD(content, ...)\
    CLOSE_SCOPE(\
        head,\
        content,\
        __VA_ARGS__\
    )
#define META(content, ...)\
    CLOSE_SCOPE(\
        meta,\
        content,\
        __VA_ARGS__\
    )
#define BASE(content, ...)\
    CLOSE_SCOPE(\
        base,\
        content,\
        __VA_ARGS__\
    )
#define TITLE(content, ...)\
    CLOSE_SCOPE(\
        title,\
        content,\
        __VA_ARGS__\
    )
#define BODY(content, ...)\
    CLOSE_SCOPE(\
        body,\
        content,\
        __VA_ARGS__\
    )
#define PARAGRAPH(content, ...)\
    CLOSE_SCOPE(\
        p,\
        content,\
        __VA_ARGS__\
    )
#define H1(content, ...)\
    CLOSE_SCOPE(\
        h1,\
        content,\
        __VA_ARGS__\
    )
#define H2(content, ...)\
    CLOSE_SCOPE(\
        h2,\
        content,\
        __VA_ARGS__\
    )
#define H3(content, ...)\
    CLOSE_SCOPE(\
        h3,\
        content,\
        __VA_ARGS__\
    )
#define H4(content, ...)\
    CLOSE_SCOPE(\
        h4,\
        content,\
        __VA_ARGS__\
    )
#define H5(content, ...)\
    CLOSE_SCOPE(\
        h5,\
        content,\
        __VA_ARGS__\
    )
#define H6(content, ...)\
    CLOSE_SCOPE(\
        h6,\
        content,\
        __VA_ARGS__\
    )
#define BR(...)\
    CLOSE_NONE(\
        br\
    )
#define HR(...)\
    CLOSE_NONE(\
        hr\
    )
// ============================================================================
// HTML - Formatting
// ============================================================================
#define ACRONYM(content, ...)\
    CLOSE_SCOPE(\
        acronym,\
        content,\
        __VA_ARGS__\
    )
#define ABBR(content, ...)\
    CLOSE_SCOPE(\
        abbr,\
        content,\
        __VA_ARGS__\
    )
#define ADDRESS(content, ...)\
    CLOSE_SCOPE(\
        address,\
        content,\
        __VA_ARGS__\
    )
#define B(content, ...)\
    CLOSE_SCOPE(\
        b,\
        content,\
        __VA_ARGS__\
    )
#define BDI(content, ...)\
    CLOSE_SCOPE(\
        bdi,\
        content,\
        __VA_ARGS__\
    )
#define BDO(content, ...)\
    CLOSE_SCOPE(\
        bdo,\
        content,\
        __VA_ARGS__\
    )
#define BIG(content, ...)\
    CLOSE_SCOPE(\
        big,\
        content,\
        __VA_ARGS__\
    )
#define BLOCKQUOTE(content, ...)\
    CLOSE_SCOPE(\
        blockquote,\
        content,\
        __VA_ARGS__\
    )
#define CENTER(content, ...)\
    CLOSE_SCOPE(\
        center,\
        content,\
        __VA_ARGS__\
    )
#define CITE(content, ...)\
    CLOSE_SCOPE(\
        cite,\
        content,\
        __VA_ARGS__\
    )
#define CODE(content, ...)\
    CLOSE_SCOPE(\
        code,\
        content,\
        __VA_ARGS__\
    )
#define DEL(content, ...)\
    CLOSE_SCOPE(\
        del,\
        content,\
        __VA_ARGS__\
    )
#define DFN(content, ...)\
    CLOSE_SCOPE(\
        dfn,\
        content,\
        __VA_ARGS__\
    )
#define EM(content, ...)\
    CLOSE_SCOPE(\
        em,\
        content,\
        __VA_ARGS__\
    )
#define FONT(content, ...)\
    CLOSE_SCOPE(\
        font,\
        content,\
        __VA_ARGS__\
    )
#define I(content, ...)\
    CLOSE_SCOPE(\
        i,\
        content,\
        __VA_ARGS__\
    )
#define INS(content, ...)\
    CLOSE_SCOPE(\
        ins,\
        content,\
        __VA_ARGS__\
    )
#define KBD(content, ...)\
    CLOSE_SCOPE(\
        kbd,\
        content,\
        __VA_ARGS__\
    )
#define MARK(content, ...)\
    CLOSE_SCOPE(\
        mark,\
        content,\
        __VA_ARGS__\
    )
#define METER(content, ...)\
    CLOSE_SCOPE(\
        meter,\
        content,\
        __VA_ARGS__\
    )
#define PRE(content, ...)\
    CLOSE_SCOPE(\
        pre,\
        content,\
        __VA_ARGS__\
    )
#define PROGRESS(content, ...)\
    CLOSE_SCOPE(\
        progress,\
        content,\
        __VA_ARGS__\
    )
#define Q(content, ...)\
    CLOSE_SCOPE(\
        q,\
        content,\
        __VA_ARGS__\
    )
#define RP(content, ...)\
    CLOSE_SCOPE(\
        rp,\
        content,\
        __VA_ARGS__\
    )
#define RT(content, ...)\
    CLOSE_SCOPE(\
        rt,\
        content,\
        __VA_ARGS__\
    )
#define RUBY(content, ...)\
    CLOSE_SCOPE(\
        ruby,\
        content,\
        __VA_ARGS__\
    )
#define S(content, ...)\
    CLOSE_SCOPE(\
        s,\
        content,\
        __VA_ARGS__\
    )
#define SAMP(content, ...)\
    CLOSE_SCOPE(\
        samp,\
        content,\
        __VA_ARGS__\
    )
#define SMALL(content, ...)\
    CLOSE_SCOPE(\
        small,\
        content,\
        __VA_ARGS__\
    )
#define STRIKE(content, ...)\
    CLOSE_SCOPE(\
        strike,\
        content,\
        __VA_ARGS__\
    )
#define STRONG(content, ...)\
    CLOSE_SCOPE(\
        strong,\
        content,\
        __VA_ARGS__\
    )
#define SUB(content, ...)\
    CLOSE_SCOPE(\
        sub,\
        content,\
        __VA_ARGS__\
    )
#define SUP(content, ...)\
    CLOSE_SCOPE(\
        sup,\
        content,\
        __VA_ARGS__\
    )
#define TEMPLATE(content, ...)\
    CLOSE_SCOPE(\
        template,\
        content,\
        __VA_ARGS__\
    )
#define TIME(content, ...)\
    CLOSE_SCOPE(\
        time,\
        content,\
        __VA_ARGS__\
    )
#define TT(content, ...)\
    CLOSE_SCOPE(\
        tt,\
        content,\
        __VA_ARGS__\
    )
#define U(content, ...)\
    CLOSE_SCOPE(\
        u,\
        content,\
        __VA_ARGS__\
    )
#define VAR(content, ...)\
    CLOSE_SCOPE(\
        var,\
        content,\
        __VA_ARGS__\
    )
#define WBR(content, ...)\
    CLOSE_SCOPE(\
        wbr,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Forms & Inputs
// ============================================================================
#define FORM(content, ...)\
    CLOSE_SCOPE(\
        form,\
        content,\
        __VA_ARGS__\
    )
#define INPUT(content, ...)\
    CLOSE_SCOPE(\
        input,\
        content,\
        __VA_ARGS__\
    )
#define TEXTAREA(content, ...)\
    CLOSE_SCOPE(\
        textarea,\
        content,\
        __VA_ARGS__\
    )
#define BUTTON(content, ...)\
    CLOSE_SCOPE(\
        button,\
        content,\
        __VA_ARGS__\
    )
#define SELECT(content, ...)\
    CLOSE_SCOPE(\
        select,\
        content,\
        __VA_ARGS__\
    )
#define OPTGROUP(content, ...)\
    CLOSE_SCOPE(\
        optgroup,\
        content,\
        __VA_ARGS__\
    )
#define OPTION(content, ...)\
    CLOSE_SCOPE(\
        option,\
        content,\
        __VA_ARGS__\
    )
#define LABEL(content, ...)\
    CLOSE_SCOPE(\
        label,\
        content,\
        __VA_ARGS__\
    )
#define LEGEND(content, ...)\
    CLOSE_SCOPE(\
        legend,\
        content,\
        __VA_ARGS__\
    )
#define DATALIST(content, ...)\
    CLOSE_SCOPE(\
        datalist,\
        content,\
        __VA_ARGS__\
    )
#define OUTPUT(content, ...)\
    CLOSE_SCOPE(\
        OUTPUT,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Frames
// ============================================================================
#define IFRAME(content, ...)\
    CLOSE_SCOPE(\
        iframe,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Images
// ============================================================================
#define IMG(content, ...)\
    CLOSE_SCOPE(\
        img,\
        content,\
        __VA_ARGS__\
    )
#define MAP(content, ...)\
    CLOSE_SCOPE(\
        map,\
        content,\
        __VA_ARGS__\
    )
#define AREA(content, ...)\
    CLOSE_SCOPE(\
        area,\
        content,\
        __VA_ARGS__\
    )
#define CANVAS(content, ...)\
    CLOSE_SCOPE(\
        canvas,\
        content,\
        __VA_ARGS__\
    )
#define FIGCAPTION(content, ...)\
    CLOSE_SCOPE(\
        figcaption,\
        content,\
        __VA_ARGS__\
    )
#define FIGURE(content, ...)\
    CLOSE_SCOPE(\
        figure,\
        content,\
        __VA_ARGS__\
    )
#define PICTURE(content, ...)\
    CLOSE_SCOPE(\
        picture,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Audio/Video
// ============================================================================
#define AUDIO(content, ...)\
    CLOSE_SCOPE(\
        audio,\
        content,\
        __VA_ARGS__\
    )
#define SOURCE(content, ...)\
    CLOSE_SCOPE(\
        source,\
        content,\
        __VA_ARGS__\
    )
#define TRACK(content, ...)\
    CLOSE_SCOPE(\
        track,\
        content,\
        __VA_ARGS__\
    )
#define VIDEO(content, ...)\
    CLOSE_SCOPE(\
        video,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Links
// ============================================================================
#define A(content, ...)\
    CLOSE_SCOPE(\
        a,\
        content,\
        __VA_ARGS__\
    )
#define LINK(content, ...)\
    CLOSE_SCOPE(\
        link,\
        content,\
        __VA_ARGS__\
    )
#define NAV(content, ...)\
    CLOSE_SCOPE(\
        nav,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Lists
// ============================================================================
#define UL(content, ...)\
    CLOSE_SCOPE(\
        ul,\
        content,\
        __VA_ARGS__\
    )
#define OL(content, ...)\
    CLOSE_SCOPE(\
        ol,\
        content,\
        __VA_ARGS__\
    )
#define LI(content, ...)\
    CLOSE_SCOPE(\
        li,\
        content,\
        __VA_ARGS__\
    )
#define DIR(content, ...)\
    CLOSE_SCOPE(\
        dir,\
        content,\
        __VA_ARGS__\
    )
#define DL(content, ...)\
    CLOSE_SCOPE(\
        dl,\
        content,\
        __VA_ARGS__\
    )
#define DT(content, ...)\
    CLOSE_SCOPE(\
        dt,\
        content,\
        __VA_ARGS__\
    )
#define DD(content, ...)\
    CLOSE_SCOPE(\
        dd,\
        content,\
        __VA_ARGS__\
    )
#define MENU(content, ...)\
    CLOSE_SCOPE(\
        menu,\
        content,\
        __VA_ARGS__\
    )
#define MENUITEM(content, ...)\
    CLOSE_SCOPE(\
        menuitem,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Tables
// ============================================================================
#define TABLE(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define CAPTION(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define TH(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define TR(content, ...)\
    CLOSE_SCOPE(\
        tr,\
        content,\
        __VA_ARGS__\
    )
#define TD(content, ...)\
    CLOSE_SCOPE(\
        td,\
        content,\
        __VA_ARGS__\
    )
#define THEAD(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define TBODY(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define TFOOT(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define COL(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
#define COLGROUP(content, ...)\
    CLOSE_SCOPE(\
        table,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Style & Semantics
// ============================================================================
#define STYLE(content, ...)\
    CLOSE_SCOPE(\
        style,\
        content,\
        __VA_ARGS__\
    )
#define DIV(content, ...)\
    CLOSE_SCOPE(\
        div,\
        content,\
        __VA_ARGS__\
    )
#define SPAN(content, ...)\
    CLOSE_SCOPE(\
        span,\
        content,\
        __VA_ARGS__\
    )
#define SPAN(content, ...)\
    CLOSE_SCOPE(\
        span,\
        content,\
        __VA_ARGS__\
    )
#define HEADER(content, ...)\
    CLOSE_SCOPE(\
        header,\
        content,\
        __VA_ARGS__\
    )
#define FOOTER(content, ...)\
    CLOSE_SCOPE(\
        footer,\
        content,\
        __VA_ARGS__\
    )
#define MAIN(content, ...)\
    CLOSE_SCOPE(\
        main,\
        content,\
        __VA_ARGS__\
    )
#define SECTION(content, ...)\
    CLOSE_SCOPE(\
        section,\
        content,\
        __VA_ARGS__\
    )
#define ARTICLE(content, ...)\
    CLOSE_SCOPE(\
        article,\
        content,\
        __VA_ARGS__\
    )
#define ASIDE(content, ...)\
    CLOSE_SCOPE(\
        aside,\
        content,\
        __VA_ARGS__\
    )
#define DETAILS(content, ...)\
    CLOSE_SCOPE(\
        header,\
        content,\
        __VA_ARGS__\
    )
#define DIALOG(content, ...)\
    CLOSE_SCOPE(\
        footer,\
        content,\
        __VA_ARGS__\
    )
#define SUMMARY(content, ...)\
    CLOSE_SCOPE(\
        summary,\
        content,\
        __VA_ARGS__\
    )
#define DATA(content, ...)\
    CLOSE_SCOPE(\
        data,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - Programming
// ============================================================================
#define SCRIPT(content, ...)\
    CLOSE_SCOPE(\
        script,\
        content,\
        __VA_ARGS__\
    )
#define NOSCRIPT(content, ...)\
    CLOSE_SCOPE(\
        noscript,\
        content,\
        __VA_ARGS__\
    )
#define EMBED(content, ...)\
    CLOSE_SCOPE(\
        embed,\
        content,\
        __VA_ARGS__\
    )
#define OBJECT(content, ...)\
    CLOSE_SCOPE(\
        object,\
        content,\
        __VA_ARGS__\
    )
#define PARAM(content, ...)\
    CLOSE_SCOPE(\
        param,\
        content,\
        __VA_ARGS__\
    )
// ============================================================================
// HTML - CSS & JS
// ============================================================================
#define STYLESHEET(path)\
    CLOSE_NONE(\
        link,\
        ATTRIBUTE(href,path)\
    )

#endif
