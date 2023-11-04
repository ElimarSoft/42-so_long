/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:11:33 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/24 12:14:40 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define RESIZEREQUEST 25
# define CIRCULATENOTIFY 26
# define CIRCULATEREQUEST 27
# define PROPERTYNOTIFY 28
# define SELECTIONCLEAR 29
# define SELECTIONREQUEST 30
# define SELECTIONNOTIFY 31
# define COLORMAPNOTIFY 32
# define CLIENTMESSAGE 33
# define MAPPINGNOTIFY 34
# define GENERICEVENT 35
# define LASTEVENT 36
# define NOEVENTMASK 0L
# define KEYPRESSMASK 0x00000001L
# define KEYRELEASEMASK 0x00000002L
# define BUTTONPRESSMASK 0x00000004L
# define BUTTONRELEASEMASK 0x00000008L
# define ENTERWINDOWMASK 0x00000010L
# define LEAVEWINDOWMASK 0x00000020L
# define POINTERMOTIONMASK 0x00000040L
# define POINTERMOTIONHINTMASK 0x00000080L
# define BUTTON1MOTIONMASK 0x00000100L
# define BUTTON2MOTIONMASK 0x00000200L
# define BUTTON3MOTIONMASK 0x00000400L
# define BUTTON4MOTIONMASK 0x00000800L
# define BUTTON5MOTIONMASK 0x00001000L
# define BUTTONMOTIONMASK 0x00002000L
# define KEYMAPSTATEMASK 0x00004000L
# define EXPOSUREMASK 0x00008000L
# define VISIBILITYCHANGEMASK 0x00010000L
# define STRUCTURENOTIFYMASK 0x00020000L
# define RESIZEREDIRECTMASK 0x00040000L
# define SUBSTRUCTURENOTIFYMASK 0x00080000L
# define SUBSTRUCTUREREDIRECTMASK 0x00100000L
# define FOCUSCHANGEMASK 0x00200000L
# define PROPERTYCHANGEMASK 0x00400000L
# define COLORMAPCHANGEMASK 0x00800000L
# define OWNERGRABBUTTONMASK 0x01000000L
#endif
