/* librepo - A library providing (libcURL like) API to downloading repository
 * Copyright (C) 2012  Tomas Mlcoch
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#ifndef LR_YUMREPO_H
#define LR_YUMREPO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rcodes.h"
#include "result.h"

/** \defgroup   yum       Yum repo manipulation
 *  \addtogroup yum
 *  @{
 */

/** Path to single metadata file from repomd.xml. */
typedef struct {
    char *type;  /*!< Type of record (e.g. "primary") */
    char *path;  /*!< Path to the file (e.g. foo/bar/repodata/primary.xml) */
} lr_YumRepoPath;

/** Yum repository */
typedef struct {
    GSList *paths;      /*!< Paths to repo files. List of ::lr_YumRepoPath*s */
    char *repomd;       /*!< Path to repomd.xml */
    char *url;          /*!< URL from where repo was downloaded */
    char *destdir;      /*!< Local path to the repo */
    char *signature;    /*!< Path to signature if available and
                             signature was downloaded (GPG check
                             was enabled during repo downloading) */
    char *mirrorlist;   /*!< Mirrolist file */
} lr_YumRepo;

/** Allocate new yum repo object.
 * @return              New yum repo object.
 */
lr_YumRepo *
lr_yum_repo_init();

/** Free yum repo - free its item and the repo itself.
 * @param repo          Yum repo object.
 */
void
lr_yum_repo_free(lr_YumRepo *repo);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
