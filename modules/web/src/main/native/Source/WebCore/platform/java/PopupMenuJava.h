/*
 * Copyright (c) 2011, 2017, Oracle and/or its affiliates. All rights reserved.
 */

#pragma once

#include "IntRect.h"
#include "PopupMenu.h"
#include <wtf/PassRefPtr.h>
#include <wtf/RefCounted.h>

namespace WebCore {

class FrameView;
class Scrollbar;
class PopupMenuClient;

class PopupMenuJava : public PopupMenu {
public:
    PopupMenuJava(PopupMenuClient*);
    ~PopupMenuJava();

    virtual void show(const IntRect&, FrameView*, int index);
    virtual void hide();
    virtual void updateFromElement();
    virtual void disconnectClient();

    void createPopupMenuJava(Page* page);
    void populate();
    PopupMenuClient* client() const { return m_popupClient; }

private:
    PopupMenuClient* m_popupClient;
    JGObject m_popup;
};

} // namespace WebCore
