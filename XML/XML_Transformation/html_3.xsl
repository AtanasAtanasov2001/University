<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Игра</h1>
                <table border="5" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Рейтинг</th>
                        <th>Жанр</th>
                        <th>Език на играта</th>
                        <th>Издател</th> 
                    </tr>         
                    <xsl:for-each select="game_library/game">
                        <tr>
                            <td>
                                <xsl:call-template name="game-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-rating"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-genres-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-languages-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-publisher"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="game-name">
        <xsl:value-of select="game_name/."/>
    </xsl:template>

    <xsl:template name="game-rating">
        <xsl:value-of select="rating/."/>
    </xsl:template>

    <xsl:template name="game-genres-name">
        <xsl:value-of select="genres/genre/@name/."/>
    </xsl:template>

    <xsl:template name="game-languages-name">
        <xsl:value-of select="language/@name/."/>
    </xsl:template>

    <xsl:template name="game-publisher">
        <xsl:value-of select="publisher/."/>
    </xsl:template>

</xsl:stylesheet>